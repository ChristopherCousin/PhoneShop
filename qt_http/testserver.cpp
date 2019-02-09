#include "testserver.h"


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
        xmlManager.makeFiles("order", message);
        if (xmlManager.validatexml("newOrder.xml", "newOrder.xsd"))
        {
            newOrder();
        }
    }
    else if (message.mid(0, 5) == "find ")
    {
        message.remove(0, 5);
        xmlManager.makeFiles("find", message);
        if (xmlManager.validatexml("findOrder.xml", "findOrder.xsd"))
        {
            respuesta = xmlManager.writeOrderStatusXml(findOrder());

            pClient->sendTextMessage("9findOrder" + respuesta);

        }
    }
    else if (message.mid(0, 5) == "login")
    {
        message.remove(0, 5);
        xmlManager.makeFiles("login", message);
        if (xmlManager.validatexml("Login.xml", "Login.xsd"))
        {
            respuesta = checkLogin();
            pClient->sendTextMessage("5login" +respuesta);
        }
    }

}

void TestServer::newOrder()
{
        auto newOrderXml = xmlManager.readNewOrder();
        QSqlQuery query("INSERT INTO "
                        "orders(statusorders,phoneorders,repairorders,"
                        "orderidorders,dateorders) values('On the way of the technician','"
                + std::get<0>(newOrderXml) + "', '" + std::get<1>(newOrderXml) + "', '" + std::get<2>(newOrderXml) + "',current_timestamp);",
            db);

        if(!query.lastError().isValid())
        {
            qDebug() << "Error en consulta: " << query.lastError();
        }
    }


QString TestServer::findOrder()
{
        QString idorder = xmlManager.readFindOrder();
        QString result{""};
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

       return result;
}

QString TestServer::checkLogin()
{

    auto LoginXML = xmlManager.readLogin();
    QString result{""};
        QSqlQuery query(
            "SELECT * FROM users WHERE iduser ='" + std::get<0>(LoginXML) + "' AND passworduser = '" + std::get<1>(LoginXML) + "'", db);
        query.next();
        if(query.lastError().isValid())
        {
            result = "Error";
        }
        else if(query.numRowsAffected() == 0)
        {
            result = "No";
        } else {
           result = xmlManager.writeLoginXml(query.value(0).toString());
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
