#include "testserver.h"
#include "QtWebSockets/qwebsocketserver.h"
#include "QtWebSockets/qwebsocket.h"
#include <QtCore/QDebug>

TestServer::TestServer(quint16 port) :
    m_pWebSocketServer(new QWebSocketServer(QStringLiteral("Test Server"),
                                            QWebSocketServer::NonSecureMode, this))
{

    if (m_pWebSocketServer->listen(QHostAddress::Any, port))
    {
        qDebug() << "Server iniciado en puerto:" << port;
        connect(m_pWebSocketServer, &QWebSocketServer::newConnection, this, &TestServer::onNewConnection);
        connect(m_pWebSocketServer, &QWebSocketServer::closed, this, &TestServer::closed);
    } // end if

    connectDatabase();
}


TestServer::~TestServer()
{
    m_pWebSocketServer->close();
    qDeleteAll(m_clients.begin(), m_clients.end());
}


void TestServer::connectDatabase(){

        db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName("127.0.0.1");
        db.setPort(5432);
        db.setDatabaseName("phoneshop");
        db.setUserName("usuario");
        db.setPassword("usuario");
        bool ok = db.open();
        if(!ok){

        }
}
void TestServer::onNewConnection()
{
    QWebSocket *pSocket = m_pWebSocketServer->nextPendingConnection();

    qDebug() << "Socket conectado:" << pSocket;

    connect(pSocket, &QWebSocket::textMessageReceived, this, &TestServer::processTextMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &TestServer::socketDisconnected);

    m_clients << pSocket;
}


void TestServer::processTextMessage(QString message)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    qDebug() << "1";
    qDebug() << "De:" << pClient << "Mensaje recibido:" << message;

    QFile file("newOrder.xml");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file for writting";
    } else {
        QTextStream stream(&file);
        stream << message;
        file.close();
    }
    newOrderXML.setContent(&file);
    readOrderXML();
    qDebug() << "1";

}

void TestServer::readOrderXML()
{
    QDomElement root = newOrderXML.documentElement();
    QDomElement Component = root.firstChild().toElement();
    QString idorder;
    QString repair;
    QString phone;
    while(!Component.isNull())
    {
        qDebug() << "2";
        if (Component.tagName() == "Order")
        {
            QDomElement Child = Component.firstChild().toElement();

            while (!Child.isNull())
            {
                if (Child.tagName()=="IdOrder") idorder = Child.firstChild().toText().data();
                if (Child.tagName()=="repair") repair = Child.firstChild().toText().data();
                if (Child.tagName()=="Phone") phone = Child.firstChild().toText().data();

                Child = Child.nextSibling().toElement();
            }
        }
        Component = Component.nextSibling().toElement();
        QSqlQuery query("INSERT INTO orders(statusorders,phoneorders,repairorders,orderidorders) values('in process','" + phone + "', '" + repair + "', '" + idorder + "');", db);
        qDebug() << query.result() << "asd";
    }

}

void TestServer::socketDisconnected()
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    qDebug() << "Socket desconectado:" << pClient;

    if (pClient)
    {
        m_clients.removeAll(pClient);
        pClient->deleteLater();
    } // end if
}
