#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectDataBase();
    availablePhones();
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

    if(!ok){
        QMessageBox::information(this, "Warning", "Failed to connect to the DataBase");
    }
}


void MainWindow::availablePhones()
{
    QSqlQuery query("SELECT * FROM availablephones", db);
    while(query.next())
    {
        QString availablePhone = query.value(0).toString();
        ui->comboBox->addItem(availablePhone);
    }
    if(ui->comboBox->currentText() == "")
    {
        ui->lineEdit_Repairname->setDisabled(true);
        ui->lineEdit_Repairprice->setDisabled(true);
        ui->btn_AddRepair->setDisabled(true);

    } else {
        ui->lineEdit_Repairname->setDisabled(false);
        ui->lineEdit_Repairprice->setDisabled(false);
        ui->btn_AddRepair->setDisabled(false);
    }
}

void MainWindow::on_btn_AddPhone_clicked()
{
    QSqlQuery query("INSERT INTO availablephones(nombreavailablephones) values('" + ui->lineEdit->text() + "');", db);
    if(query.isValid())
    {
        QMessageBox::information(this, "Accepted", "The phone were added correctly!");
    } else {
        QMessageBox::information(this, "Warning", "We can't repair this Phone!");
        ui->comboBox->clear();
        availablePhones();
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



void MainWindow::on_btn_deletePhone_clicked()
{
    QMessageBox msgBox;
    msgBox.setInformativeText("This will delete the phone of our DataBase, are you sure?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    int ret = msgBox.exec();

    switch (ret) {
      case QMessageBox::Ok:
    {
          QSqlQuery query("DELETE FROM availablephones WHERE nombreavailablephones = '" + ui->comboBox->currentText()+ "'");
          ui->comboBox->clear();
          availablePhones();
          break;
    }
      case QMessageBox::Cancel:

          break;
    }
}

void MainWindow::on_btn_AddRepair_clicked()
{
    QSqlQuery query("INSERT INTO availablerepairs (phonenameavailablerepairs, repairnameavailablerepairs,"
                    " priceavailablerepairs) VALUES ('" + ui->comboBox->currentText() + "',"
                    " '" + ui->lineEdit_Repairname->text() + "', " + ui->lineEdit_Repairprice->text() + ")", db);

}
