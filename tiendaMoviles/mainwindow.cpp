#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer::singleShot(0, this, SLOT(go()));
    loadXML();
    readPhonesXML();
    ui->tabWidget->tabBar()->setCurrentIndex(0);
    ui->tabWidget->tabBar()->hide();
    this->setFixedSize(518,300);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::go()
{
    m_webSocket = new Websocket(QUrl("ws://localhost:3344"));
    connect(m_webSocket, SIGNAL(recibirmensaje(QString)), this, SLOT(recibirmensaje(QString)));
}


void MainWindow::loadXML()
{
    // Cargar el XML como RAW Data
    QFile f("AvailablePhones.xml");
    if (!f.open(QIODevice::ReadOnly))
    {
        // Error
        std::cerr << "Error while loading file" << std::endl;
    }

    xmlBOM.setContent(&f);

    f.close();


    QFile repairs("AvailableRepairs.xml");
    if (!f.open(QIODevice::ReadOnly))
    {
        // Error
        std::cerr << "Error while loading repairs XML file" << std::endl;
    }


    xmlRepairs.setContent(&repairs);
    repairs.close();
}

void MainWindow::readPhonesXML()
{
    // Extraemos el root markup
    QDomElement root = xmlBOM.documentElement();

    // COgemos el primer hijo del root
    QDomElement Component = root.firstChild().toElement();


    // Loop mientras haya un hijo
    while (!Component.isNull())
    {


        if (Component.tagName() == "Phone")
        {

            // Cogemos el primer hijo de phone
            QDomElement Child = Component.firstChild().toElement();

            QString Name;

            // leemos cada hijo del componente nodo
            while (!Child.isNull())
            {

                // leemos el nombre
                if (Child.tagName() == "Name")
                    Name = Child.firstChild().toText().data();


                Child = Child.nextSibling().toElement();
            }

            // ponemos en el comboBox los moviles disponibles
            ui->comboBox->addItem(Name.toStdString().c_str());
        }


        // Siguiente componente
        Component = Component.nextSibling().toElement();
    }
}

void MainWindow::readRepairsXML()
{
    QDomElement root = xmlRepairs.documentElement();

    QDomElement Component = root.firstChild().toElement();

    while (!Component.isNull())
    {
        if (Component.tagName() == "Phone")
        {

            QDomElement Child = Component.firstChild().toElement();

            QString name;
            QString repair;
            while (!Child.isNull())
            {

                if (Child.tagName() == "Name")
                    name = Child.firstChild().toText().data();
                if (name == ui->comboBox->currentText())
                {
                    Child = Child.nextSibling().toElement();

                    if (Child.tagName() == "Repair")
                    {
                        repair = Child.firstChild().toText().data();
                        ui->comboBox_2->addItem(repair);
                    }
                }


                Child = Child.nextSibling().toElement();
            }
        }

        Component = Component.nextSibling().toElement();
    }
}

void MainWindow::writeOrderXML()
{

    QDomDocument document;
    QDomElement root = document.createElement("Orders");


    QDomElement order = document.createElement("Order");
    QDomElement idorder = document.createElement("IdOrder");
    QDomElement phone = document.createElement("Phone");
    QDomElement repair = document.createElement("repair");


    QUuid idordert = QUuid::createUuid();
    QString phonet = ui->comboBox->currentText();
    QString repairt = ui->comboBox_2->currentText();

    QDomText idordertxt = document.createTextNode(idordert.toString());
    QDomText phonetxt = document.createTextNode(phonet);
    QDomText repairtxt = document.createTextNode(repairt);


    idorder.appendChild(idordertxt);
    repair.appendChild(repairtxt);
    phone.appendChild(phonetxt);
    order.appendChild(idorder);
    order.appendChild(repair);
    order.appendChild(phone);
    root.appendChild(order);
    document.appendChild(root);

    QString message = "order" + document.toString();
    m_webSocket->sendXML(message);

    // escribimos en el file
    QFile file("newOrder.xml");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file for writting";
    }
    else
    {
        QTextStream stream(&file);
        stream << document.toString();


        file.close();
    }
}

void MainWindow::writeFindOrderXML()
{

    QDomDocument document;
    QDomElement root = document.createElement("Orders");


    QDomElement order = document.createElement("Order");
    QDomElement idorder = document.createElement("IdOrder");


    QDomText idordertxt = document.createTextNode(ui->lineEdit_2->text());


    idorder.appendChild(idordertxt);
    order.appendChild(idorder);
    root.appendChild(order);
    document.appendChild(root);

    QString message = "find " + document.toString();
    m_webSocket->sendXML(message);

    // escribimos en el file
    QFile file("FindOrder.xml");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file for writting";
    }
    else
    {
        QTextStream stream(&file);
        stream << document.toString();

        file.close();
    }
}


void MainWindow::recibirmensaje(QString message)
{
    if(message == "done")
    {
        ui->result_label->setStyleSheet({"QLabel{ color:green;}"});
    } else {
        ui->result_label->setStyleSheet({""});
    }
    ui->result_label->setText(message);
}

void MainWindow::on_comboBox_currentTextChanged(const QString& arg1)
{
    ui->comboBox_2->clear();
    readRepairsXML();
}


void MainWindow::on_btn_newRepair_clicked()
{
    writeOrderXML();
}

void MainWindow::on_btn_findOrder_clicked()
{
    writeFindOrderXML();
    //ui->result_label->setText(Websocket::statusMessage);

}

void MainWindow::on_actionLogin_triggered()
{
    ui->tabWidget->tabBar()->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tabWidget->tabBar()->setCurrentIndex(0);
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    switch(index)
    {
    case 0:
        this->setFixedSize(518,300);
        break;
    case 1:
        this->setFixedSize(518,345);
        break;
    }
}
