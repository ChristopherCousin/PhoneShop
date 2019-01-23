#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtXml>
#include <QFile>
#include <QDebug>
#include <iostream>
#include "websocket.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void loadXML();
    void readXML();


    // el qdomdocumento representara un documento xml
    QDomDocument xmlBOM;

private slots:
    void go();

private:
    Ui::MainWindow *ui;
    Websocket *m_webSocket;
};

#endif // MAINWINDOW_H
