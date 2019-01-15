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

void MainWindow::on_btn_AddPhone_clicked()
{
    QSqlQuery query("INSERT INTO availablephones(nombreavailablephones) values('" + ui->lineEdit->text() + "');", db);
    if(query.isValid())
    {
        QMessageBox::information(this, "Accepted", "The phone were added correctly!");
    } else {
        QMessageBox::information(this, "Warning", "We can't repair this Phone!");
    }
}

void MainWindow::on_btn_WriteXML_clicked()
{
    // Escribimos el XML
    QDomDocument document;

    QDomElement root = document.createElement("Phones");

    // lo añadimos al archivo
    document.appendChild(root);

    QDomElement phone = document.createElement("Phone");
    root.appendChild(phone);

    QDomElement namePhone = document.createElement("Name");
    phone.appendChild(namePhone);

    //escribimos en el file
    QFile file("AvailablePhones.xml");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file for writting";
    } else {
        QTextStream stream(&file);
        stream << document.toString();
        file.close();
    }
}
