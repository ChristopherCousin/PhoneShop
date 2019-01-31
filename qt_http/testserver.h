#ifndef TESTSERVER_H
#define TESTSERVER_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QByteArray>
#include <QFile>
#include <QXmlStreamReader>
#include <iostream>
#include <QDomDocument>
#include <QSqlQuery>
#include <QSql>
#include <QtXmlPatterns/QXmlSchema>
#include <QtXmlPatterns/QXmlSchemaValidator>
#include <QXmlSchema>
#include <QCoreApplication>

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
    QDomDocument newOrderXML;
    QDomDocument findOrderXML;
    QSqlDatabase db;
    void connectDatabase();
    bool validatexml(QString xml, QString xsd);
    void checkProcessOrders();
    void checkQueueOrders();
    void sendXML(QString xml);

signals:
    void closed();

private slots:
    void onNewConnection();
    void processTextMessage(QString message);
    void socketDisconnected();

private:
    QWebSocketServer *m_pWebSocketServer;
    QList<QWebSocket *> m_clients;
};

#endif
