#ifndef DBCONNECTION_H
#define DBCONNECTION_H
#include <QtSql>
#include <QDebug>
#include <QSqlQuery>

class DbConnection
{
public:
    DbConnection();
    connectDataBase();
    QSqlDatabase db;

};

#endif // DBCONNECTION_H
