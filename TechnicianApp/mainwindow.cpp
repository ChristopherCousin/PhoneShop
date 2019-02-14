#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer::singleShot(0, this, SLOT(go()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::go()
{
    m_webSocket = new Websocket(QUrl("ws://localhost:3344"));
    connect(m_webSocket, SIGNAL(receivemessage(QString)), this, SLOT(receivemessage(QString)));
}


void MainWindow::receivemessage(QString message)
{
    QString xmlToValidate = xmlManager.xmlMessage(message);

    if (xmlToValidate == "orders")
    {
        QString xmlName = xmlManager.makeFiles("orders", message);

        if (xmlManager.validatexml(xmlName, "Orders.xsd"))
        {
            availableOrders(message);
        }
    }
}


void MainWindow::requestXML()
{
    m_webSocket->sendXML(xmlManager.writeRequestOrdersXml());
}

void MainWindow::on_pushButton_clicked()
{
    QString message = xmlManager.writeNewOrderStatus(ui->label_orderid->text(), ui->lineEdit_newStatus->text());
    m_webSocket->sendXML(message);
    on_btn_refresh_clicked();
    QString message2 = xmlManager.writeUpdateStatusXml(ui->label_orderid->text(), ui->lineEdit_newStatus->text());
    m_webSocket->sendXML(message2);

}

void MainWindow::availableOrders(QString xml)
{
    setOrdersVectors(xml);
    setOrdersInfo();
}

void MainWindow::setOrdersVectors(QString xml)
{
    auto readedorders = xmlManager.readOrdersXML(xml);
    orders.idOrder = std::get<0>(readedorders);
    orders.phone = std::get<1>(readedorders);
    orders.repair = std::get<2>(readedorders);
    orders.date = std::get<3>(readedorders);
    orders.status = std::get<4>(readedorders);
}

void MainWindow::setOrdersInfo()
{
    for(int x; x <= orders.repair.size() -1;x++)
    {
        ui->comboBox_Repairs->addItem(QString::number(x));
    }
}

void MainWindow::on_comboBox_Repairs_currentIndexChanged(const QString &arg1)
{
    ui->label_orderid->setText(orders.idOrder.at(ui->comboBox_Repairs->currentText().toInt()));
    ui->label_phone->setText(orders.phone.at(ui->comboBox_Repairs->currentText().toInt()));
    ui->label_repair->setText(orders.repair.at(ui->comboBox_Repairs->currentText().toInt()));
    ui->label_status->setText(orders.status.at(ui->comboBox_Repairs->currentText().toInt()));
    ui->label_date->setText(orders.date.at(ui->comboBox_Repairs->currentText().toInt()));
}

void MainWindow::on_btn_refresh_clicked()
{
    ui->comboBox_Repairs->clear();
    requestXML();
}

void MainWindow::on_btn_finishRepair_clicked()
{
    QString message = xmlManager.writeNewOrderStatus(ui->label_orderid->text(), "done");
    m_webSocket->sendXML(message);
    on_btn_refresh_clicked();
}
