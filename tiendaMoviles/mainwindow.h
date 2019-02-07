#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtXml>
#include <QFile>
#include <QDebug>
#include <iostream>
#include <QUuid>
#include <QRect>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QtXmlPatterns/QXmlSchema>
#include <QtXmlPatterns/QXmlSchemaValidator>
#include <QXmlSchema>
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
    void readPhonesXML();
    void readRepairsXML();
    void readFoundedOrderXML();
    void readLoginXML();
    void writeOrderXML();
    void writeFindOrderXML();
    void writeLoginXML();
    void onLoginSuccessfully();
    void onLogOutSuccessfully();
    void startConfig();
    void receiveMessage();
    bool validatexml(QString xml, QString xsd);


    // el qdomdocumento representara un documento xml
    QDomDocument xmlBOM;
    QDomDocument xmlRepairs;
    QDomDocument xmlFoundedOrder;
    QDomDocument xmlLogin;
    QString username;


private slots:
    void recibirmensaje(QString);
    void go();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_btn_newRepair_clicked();

    void on_btn_findOrder_clicked();

    void on_actionLogin_triggered();

    void on_pushButton_2_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_btn_login_clicked();

    void on_actionLog_out_triggered();

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Websocket *m_webSocket;
    QSize ordersSizeWindow;
    QSize ordersSizeLabel;

};

#endif // MAINWINDOW_H
