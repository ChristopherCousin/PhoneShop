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
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setPort(5432);
    db.setDatabaseName("phoneshop");
    db.setUserName("usuario");
    db.setPassword("usuario");
    bool ok = db.open();
}

void MainWindow::on_pushButton_clicked()
{
    QSqlQuery query("INSERT INTO availablephones(nombreavailablephones) values('" + ui->lineEdit->text() + "');", db);
    if(query.isValid())
    {
        QMessageBox::information(this, "Accepted", "The phone were added correctly!");
    } else {
        QMessageBox::information(this, "Warning", "We can't repair this Phone!");
    }
}
