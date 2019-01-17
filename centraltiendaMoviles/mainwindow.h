#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QSqlQuery>
#include <QUuid>
#include <QMessageBox>
#include <iostream>
#include <QtXml>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void connectDataBase();
    void availablePhones();
    QSqlDatabase db;

private slots:
    void on_btn_AddPhone_clicked();

    void on_btn_WriteXML_clicked();


    void on_btn_deletePhone_clicked();

    void on_btn_AddRepair_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
