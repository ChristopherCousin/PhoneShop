#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QTimer>
#include "websocket.h"
#include "xmlmanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Websocket *m_webSocket;
    Xmlmanager xmlManager;

private slots:
    void go();
    void receivemessage(QString);
};


#endif // MAINWINDOW_H
