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
    startConfig();
    ui->tabWidget->tabBar()->hide();
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

void MainWindow::startConfig()
{
    ui->actionLogin->setVisible(true);
    ui->actionLog_out->setVisible(false);
    ui->label_client1->setVisible(false);
    ui->label_client2->setVisible(false);
    ui->label_client3->setVisible(false);
    ui->tabWidget->tabBar()->setCurrentIndex(0);
    ordersSizeWindow.setHeight(305);
    ordersSizeWindow.setWidth(518);
    ordersSizeLabel.setHeight(81);
    ordersSizeLabel.setWidth(471);
    this->setFixedSize(ordersSizeWindow);
    ui->statusOfOrderLabel->setFixedSize(ordersSizeLabel);
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

void MainWindow::writeLoginXML()
{


    QDomDocument document;
    QDomElement root = document.createElement("LoginInfo");


    QDomElement login = document.createElement("Login");
    QDomElement username = document.createElement("Username");
    QDomElement password = document.createElement("Password");


    QString usernamet = ui->lineEdit_username->text();
    QString passwordt = ui->lineEdit_password->text();

    QDomText usernametxt = document.createTextNode(usernamet);
    QDomText passwordtxt = document.createTextNode(passwordt);


    username.appendChild(usernametxt);
    password.appendChild(passwordtxt);
    login.appendChild(username);
    login.appendChild(password);
    root.appendChild(login);
    document.appendChild(root);

    QString message = "login" + document.toString();
    m_webSocket->sendXML(message);

    // escribimos en el file
    QFile file("Login.xml");
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
    int toCute = message.mid(0,1).toInt();
    message.remove(0,1);
    if(message.mid(0,toCute) == "findOrder")
    {
        message.remove(0,toCute);
        if(message == "done")
        {
            ui->result_label->setStyleSheet({"QLabel{ color:green;}"});
        } else {
            ui->result_label->setStyleSheet({""});
        }
            ui->result_label->setText(message);
    }
    else if(message.mid(0,toCute) == "login")
    {
        message.remove(0,toCute);
        if(message == "No")
        {
            QMessageBox::information(
                    this,
                    tr("Error"),
                    tr("Authentication failed") );
        } else {
            username = message;
            onLoginSuccessfully();
        }
    }

}

void MainWindow::onLoginSuccessfully()
{
    ui->actionLog_out->setVisible(true);
    ui->actionLogin->setVisible(false);
    int x = username.length();
    int privilege = username.mid(x-1,x).toInt();
    qDebug() << privilege;
    username.remove(x-1,x);

    if(privilege >= 1)
    {
        ui->tabWidget->tabBar()->show();
        ordersSizeWindow.setHeight(461);
        ordersSizeWindow.setWidth(518);
        ordersSizeLabel.setHeight(201);
        ui->label_client1->setVisible(true);
        ui->label_client2->setVisible(true);
        ui->label_client3->setVisible(true);
        ui->statusOfOrderLabel->setFixedSize(ordersSizeLabel);
    }
    ui->tabWidget->tabBar()->show();
    ui->tabWidget->setCurrentIndex(0);
    ui->tab_3->setEnabled(false);

}

void MainWindow::onLogOutSuccessfully()
{
    startConfig();

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
        this->setFixedSize(ordersSizeWindow);
        qDebug() << ordersSizeWindow;
        break;
    case 1:
        this->setFixedSize(518,345);
        break;
    case 2:
        this->setFixedSize(555,345);
        break;
    }
}

void MainWindow::on_btn_login_clicked()
{
    writeLoginXML();
}

void MainWindow::on_actionLog_out_triggered()
{
    onLogOutSuccessfully();
}

void MainWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{

}
