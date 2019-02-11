#ifndef TESTSERVER_H
#define TESTSERVER_H

#include <QtCore/QDebug>
#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QByteArray>
#include <iostream>
#include <QCoreApplication>
#include <tuple>
#include "xmlmanager.h"
#include "QtWebSockets/qwebsocketserver.h"
#include "QtWebSockets/qwebsocket.h"
#include "dbmanager.h"
#include "conexionws.h"


class QWebSocketServer;
class QWebSocket;


class TestServer : public QObject
{
    Q_OBJECT

public:
    explicit TestServer(quint16 port);
    ~TestServer();
    void newOrder();
    QString findOrder();
    QString checkLogin();
    void checkProcessOrders();
    void sendXML(QString xml);
    QWebSocket* pClient;


signals:
    void closed();

private slots:
    void onNewConnection();
    void processTextMessage(QString message);
    void socketDisconnected();

private:
    QWebSocketServer *m_pWebSocketServer;
    QList<QWebSocket *> m_clients;

    Xmlmanager xmlManager;
    Dbmanager dbManager;
};

#endif
