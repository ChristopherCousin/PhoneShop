#ifndef WEBSOCKET_H
#define WEBSOCKET_H

#include <QString>
#include <QUrl>
#include <QDebug>

class websocket
{
public:
    websocket();
    void onConnected();
    void onTextMessageReceived(QString message);

private:
    websocket *web;
};

#endif // WEBSOCKET_H
