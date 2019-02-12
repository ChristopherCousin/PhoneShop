#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSql>
#include <QSqlError>
#include <iostream>
#include <QSqlQuery>
#include <QString>
#include <QDebug>
#include "xmlmanager.h"


class Dbmanager
{
public:
    Dbmanager();
    void newOrder(QString phone, QString repair, QString idorder);
    QString findOrder(QString idorder);
    QString checkLogin(QString username, QString password);
    void checkProcessOrders();
    QSqlQuery availableRepairs();

private:
    QSqlDatabase db;
    Xmlmanager *xmlManager;
};

#endif // DBMANAGER_H
