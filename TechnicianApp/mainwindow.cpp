#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer::singleShot(0, this, SLOT(go()));
    m_webSocket->sendXML(xmlManager.writeRequestOrdersXml());
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
    qDebug() << message;
}

