#include "websocket.h"

Websocket::Websocket(QUrl uri, QObject *parent) :
    QObject(parent)
{
    m_uri = uri;
    m_webSocket = new QWebSocket();
    connect(m_webSocket, SIGNAL(connected()), this, SLOT(onConnected()));
    m_webSocket->open(m_uri);
}


void Websocket::onConnected()
{
    qDebug() << "WebSocket connected";
    /*
    connect(&m_webSocket, &QWebSocket::textMessageReceived,
            this, &EchoClient::onTextMessageReceived);
    m_webSocket.sendTextMessage(QStringLiteral("Hello, world!"));
    */
}

/*
void Websocket::onTextMessageReceived(QString message)
{
    if (m_debug)
        qDebug() << "Message received:" << message;
    m_webSocket.close();
}
*/
