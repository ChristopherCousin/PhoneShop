#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QTimer>
#include "websocket.h"
#include "xmlmanager.h"
#include "orders.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     void availableOrders(QString xml);
     void setOrdersVectors(QString xml);
     void setOrdersInfo();
     void requestXML();

private:
    Ui::MainWindow *ui;
    Websocket *m_webSocket;
    Xmlmanager xmlManager;
    Orders orders;

private slots:
    void go();
    void receivemessage(QString);
    void on_pushButton_clicked();
    void on_comboBox_Repairs_currentIndexChanged(const QString &arg1);
    void on_btn_refresh_clicked();
    void on_btn_finishRepair_clicked();
};


#endif // MAINWINDOW_H
