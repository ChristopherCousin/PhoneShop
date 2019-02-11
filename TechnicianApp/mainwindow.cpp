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
}
