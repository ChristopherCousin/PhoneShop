#ifndef WEBSOCKET_H
#define WEBSOCKET_H

#include <QWebSocket>
#include <QObject>
#include <QString>
#include <QDebug>
#include <QUrl>


class Websocket : public QObject
{
    Q_OBJECT
public:
    Websocket(QUrl uri, QObject *parent = nullptr);
    void sendXML(QString xml);
    static QString statusMessage;

public slots:
    void onConnected();
    void processTextMessage(QString message);

signals:
     void receivemessage(QString);


private:
    QWebSocket *m_webSocket;
    QUrl m_uri;

};

#endif // WEBSOCKET_H
