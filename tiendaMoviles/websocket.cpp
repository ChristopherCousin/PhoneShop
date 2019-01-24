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

}

void Websocket::sendXML(QString xml)
{
    m_webSocket->sendTextMessage(QString(xml));
}
