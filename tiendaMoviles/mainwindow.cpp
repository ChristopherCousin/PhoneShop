#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectDataBase();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectDataBase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setPort(5432);
    db.setDatabaseName("phoneshop");
    db.setUserName("usuario");
    db.setPassword("usuario");
    bool ok = db.open();


    if(ok)
    {
        QSqlQuery query("SELECT * FROM availablephones", db);
        while (query.next())
        {
           QString bookid = query.value(0).toString();
           ui->comboBox->addItem(bookid);
        }

    } else {

        qDebug() << "Error de conexion";
    }
}
