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

    QDomDocument document;
    QDomElement root = document.createElement("Phones");


    // --- Consulta para poner los moviles disponibles ---
    QSqlQuery query("SELECT * FROM availablephones", db);
    while(query.next())
    {
        // --------- Escribimos el XML --------
        QDomElement phone = document.createElement("Phone");
        QDomElement namePhone = document.createElement("Name");
        QString availablePhone = query.value(0).toString();
        QDomText namePhoneText = document.createTextNode(availablePhone);

        //------- añadimos ------
        namePhone.appendChild(namePhoneText);
        phone.appendChild(namePhone);
        root.appendChild(phone);
    }

    document.appendChild(root);



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
