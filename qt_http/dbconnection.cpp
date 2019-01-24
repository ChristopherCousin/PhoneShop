#include "dbconnection.h"

DbConnection::DbConnection()
{

}

void DbConnection::connectDataBase()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setPort(5432);
    db.setDatabaseName("phoneshop");
    db.setUserName("usuario");
    db.setPassword("usuario");
    bool ok = db.open();

    if(!ok){
        QMessageBox::information(this, "Warning", "Failed to connect to the DataBase");
    }
}
