#include "testserver.h"
#include "QtWebSockets/qwebsocketserver.h"
#include "QtWebSockets/qwebsocket.h"
#include <QtCore/QDebug>
#include <QSqlError>

TestServer::TestServer(quint16 port)
    : m_pWebSocketServer(new QWebSocketServer(
          QStringLiteral("Test Server"), QWebSocketServer::NonSecureMode, this))
{
    if (m_pWebSocketServer->listen(QHostAddress::Any, port))
    {
        qDebug() << "Server iniciado en puerto:" << port;
        connect(m_pWebSocketServer, &QWebSocketServer::newConnection, this,
            &TestServer::onNewConnection);
        connect(m_pWebSocketServer, &QWebSocketServer::closed, this, &TestServer::closed);
    } // end if

    connectDatabase();

}



TestServer::~TestServer()
{
    m_pWebSocketServer->close();
    qDeleteAll(m_clients.begin(), m_clients.end());
}

void TestServer::connectDatabase()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setPort(5432);
    db.setDatabaseName("phoneshop");
    db.setUserName("usuario");
    db.setPassword("usuario");
    bool ok = db.open();
    if (!ok)
    {

    }
}
void TestServer::onNewConnection()
{
    QWebSocket* pSocket = m_pWebSocketServer->nextPendingConnection();

    qDebug() << "Socket conectado:" << pSocket;

    connect(pSocket, &QWebSocket::textMessageReceived, this, &TestServer::processTextMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &TestServer::socketDisconnected);

    m_clients << pSocket;
}


void TestServer::processTextMessage(QString message)
{
    QString respuesta;
    pClient = qobject_cast<QWebSocket*>(sender());
    qDebug() << "De:" << pClient << "Mensaje recibido:" << message.mid(0, 5);

    if (message.mid(0, 5) == "order")
    {
        message.remove(0, 5);
        QFile file("newOrder.xml");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug() << "Failed to open file for writting";
        }
        else
        {
            QTextStream stream(&file);
            stream << message;
            file.close();
        }
        newOrderXML.setContent(&file);
        if (validatexml("newOrder.xml", "newOrder.xsd"))
        {
            newOrder();
        }
    }
    else if (message.mid(0, 5) == "find ")
    {
        message.remove(0, 5);
        QFile file("findOrder.xml");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug() << "Failed to open file for writting";
        }
        else
        {
            QTextStream stream(&file);
            stream << message;
            file.close();
        }
        findOrderXML.setContent(&file);
        if (validatexml("findOrder.xml", "findOrder.xsd"))
        {
            respuesta = findOrder();
            pClient->sendTextMessage(respuesta);
        }
    }

}

void TestServer::newOrder()
{
    QDomElement root = newOrderXML.documentElement();
    QDomElement Component = root.firstChild().toElement();
    QString idorder;
    QString repair;
    QString phone;
    while (!Component.isNull())
    {
        if (Component.tagName() == "Order")
        {
            QDomElement Child = Component.firstChild().toElement();

            while (!Child.isNull())
            {
                if (Child.tagName() == "IdOrder")
                    idorder = Child.firstChild().toText().data();
                if (Child.tagName() == "repair")
                    repair = Child.firstChild().toText().data();
                if (Child.tagName() == "Phone")
                    phone = Child.firstChild().toText().data();

                Child = Child.nextSibling().toElement();
            }
        }
        Component = Component.nextSibling().toElement();


        QSqlQuery query("INSERT INTO "
                        "orders(statusorders,phoneorders,repairorders,"
                        "orderidorders,dateorders) values('On the way of the technician','"
                + phone + "', '" + repair + "', '" + idorder + "',current_timestamp);",
            db);


        if(!query.lastError().isValid())
        {
            qDebug() << "There was an error in the database";
        }
    }
}

QString TestServer::findOrder()
{
    QDomElement root = findOrderXML.documentElement();
    QDomElement Component = root.firstChild().toElement();
    QString idorder;
    QString result{""};
    while (!Component.isNull())
    {
        if (Component.tagName() == "Order")
        {
            QDomElement Child = Component.firstChild().toElement();

            while (!Child.isNull())
            {
                if (Child.tagName() == "IdOrder")
                    idorder = Child.firstChild().toText().data();

                Child = Child.nextSibling().toElement();
            }
        }
        Component = Component.nextSibling().toElement();
        checkProcessOrders();
        QSqlQuery query(
            "SELECT statusorders FROM orders where orderidorders = '" + idorder + "';", db);
        query.next();
        if(query.lastError().isValid())
        {
            result = "This order does not exist";
        } else {
            result = query.value(0).toString();
        }
    }

       return result;
}

void TestServer::checkProcessOrders()
{
    QSqlQuery query(
        "SELECT orderidorders,EXTRACT(EPOCH FROM (NOW() - dateorders)),statusorders FROM orders WHERE statusorders = 'in process'", db);
    while (query.next())
    {
        if(query.lastError().isValid())
        {
            qDebug() << "Error in query checkProcressOrders";
        }
        if(query.value(1).toInt() >= 7200 && query.value(2).toString() == "in process")
        {
            QSqlQuery query2(
                "UPDATE orders SET statusorders = 'done' where orderidorders = '" +query.value(0).toString() + "';", db);
            if(query2.lastError().isValid())
            {
                qDebug() << "Error in query checkProcressOrders";
            }
        }
    }
}

void TestServer::checkQueueOrders()
{
    int queue = 0;
    QSqlQuery query(
        "SELECT orderidorders,statusorders FROM orders WHERE statusorders != 'done'", db);
    while (query.next())
    {
        if(query.value(1).toString() == "in process")
        {
            if(queue == 0)
            {
                queue++;
            } else {
                queue++;
            }
        } else {
            queue--;
        }
    }
}




bool TestServer::validatexml(QString xml, QString xsd)
{
    QFile file(xsd);
          file.open(QIODevice::ReadOnly);

          QXmlSchema schema;
          schema.load(&file, QUrl::fromLocalFile(file.fileName()));

          if (schema.isValid())
          {
              QFile file2(xml);
              file2.open(QIODevice::ReadOnly);

              QXmlSchemaValidator validator(schema);
              if (validator.validate(&file2, QUrl::fromLocalFile(file2.fileName())))
              {
                  qDebug() << "instance document is valid";
              return true;

              } else {
                  qDebug() << "instance document is invalid";
                  return false;
              }

          } else {
              qDebug() << "schema is invalid";
          }
}

void TestServer::socketDisconnected()
{
    QWebSocket* pClient = qobject_cast<QWebSocket*>(sender());
    qDebug() << "Socket desconectado:" << pClient;

    if (pClient)
    {
        m_clients.removeAll(pClient);
        pClient->deleteLater();
    } // end if
}
