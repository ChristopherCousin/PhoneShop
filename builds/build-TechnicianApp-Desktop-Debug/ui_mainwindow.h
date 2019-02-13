/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QComboBox *comboBox_Repairs;
    QLabel *label_2;
    QFrame *line;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QFrame *line_4;
    QLineEdit *lineEdit_newStatus;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_2;
    QLabel *label_9;
    QPushButton *pushButton;
    QLabel *label_10;
    QLabel *label_orderid;
    QLabel *label_phone;
    QLabel *label_repair;
    QLabel *label_status;
    QLabel *label_date;
    QPushButton *btn_refresh;
    QPushButton *btn_finishRepair;
    QWidget *tab_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(487, 544);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 91, 31));
        QFont font;
        font.setPointSize(17);
        label->setFont(font);
        comboBox_Repairs = new QComboBox(tab);
        comboBox_Repairs->setObjectName(QStringLiteral("comboBox_Repairs"));
        comboBox_Repairs->setGeometry(QRect(110, 42, 211, 32));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 441, 381));
        label_2->setStyleSheet(QLatin1String("QLabel {\n"
"border: 1px solid #CBC8C8;\n"
"border-radius: 15px;\n"
"}"));
        line = new QFrame(tab);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 80, 441, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 10, 121, 18));
        label_3->setStyleSheet(QLatin1String("QLabel{\n"
"background: solid black;\n"
"color: white;\n"
"}"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 130, 71, 31));
        QFont font1;
        font1.setPointSize(15);
        label_4->setFont(font1);
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 169, 131, 31));
        label_5->setFont(font1);
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 91, 91, 31));
        label_6->setFont(font1);
        line_4 = new QFrame(tab);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(10, 270, 441, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        lineEdit_newStatus = new QLineEdit(tab);
        lineEdit_newStatus->setObjectName(QStringLiteral("lineEdit_newStatus"));
        lineEdit_newStatus->setGeometry(QRect(150, 288, 291, 32));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 206, 131, 31));
        label_7->setFont(font1);
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 287, 121, 31));
        label_8->setFont(font1);
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(80, 330, 361, 32));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 330, 61, 31));
        label_9->setFont(font1);
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(167, 380, 131, 41));
        QFont font2;
        font2.setPointSize(13);
        pushButton->setFont(font2);
        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 240, 51, 31));
        label_10->setFont(font1);
        label_orderid = new QLabel(tab);
        label_orderid->setObjectName(QStringLiteral("label_orderid"));
        label_orderid->setGeometry(QRect(112, 99, 321, 18));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        label_orderid->setFont(font3);
        label_phone = new QLabel(tab);
        label_phone->setObjectName(QStringLiteral("label_phone"));
        label_phone->setGeometry(QRect(94, 138, 331, 18));
        label_phone->setFont(font3);
        label_repair = new QLabel(tab);
        label_repair->setObjectName(QStringLiteral("label_repair"));
        label_repair->setGeometry(QRect(150, 177, 291, 18));
        label_repair->setFont(font3);
        label_status = new QLabel(tab);
        label_status->setObjectName(QStringLiteral("label_status"));
        label_status->setGeometry(QRect(150, 214, 281, 18));
        label_status->setFont(font3);
        label_date = new QLabel(tab);
        label_date->setObjectName(QStringLiteral("label_date"));
        label_date->setGeometry(QRect(73, 248, 361, 18));
        label_date->setFont(font3);
        btn_refresh = new QPushButton(tab);
        btn_refresh->setObjectName(QStringLiteral("btn_refresh"));
        btn_refresh->setGeometry(QRect(330, 43, 101, 31));
        btn_refresh->setFont(font2);
        btn_finishRepair = new QPushButton(tab);
        btn_finishRepair->setObjectName(QStringLiteral("btn_finishRepair"));
        btn_finishRepair->setGeometry(QRect(347, 385, 91, 31));
        QFont font4;
        font4.setPointSize(10);
        btn_finishRepair->setFont(font4);
        tabWidget->addTab(tab, QString());
        label_2->raise();
        label->raise();
        comboBox_Repairs->raise();
        line->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        line_4->raise();
        lineEdit_newStatus->raise();
        label_7->raise();
        label_8->raise();
        lineEdit_2->raise();
        label_9->raise();
        pushButton->raise();
        label_10->raise();
        label_orderid->raise();
        label_phone->raise();
        label_repair->raise();
        label_status->raise();
        label_date->raise();
        btn_refresh->raise();
        btn_finishRepair->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 487, 30));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Repairs:", Q_NULLPTR));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Incomplete Repairs", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Phone:", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Repair Name:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Order ID:", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Actual Status:", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "New Status*:", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Note:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Update repair", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Date:", Q_NULLPTR));
        label_orderid->setText(QApplication::translate("MainWindow", "Press Refresh", Q_NULLPTR));
        label_phone->setText(QApplication::translate("MainWindow", "Press Refresh", Q_NULLPTR));
        label_repair->setText(QApplication::translate("MainWindow", "Press Refresh", Q_NULLPTR));
        label_status->setText(QApplication::translate("MainWindow", "Press Refresh", Q_NULLPTR));
        label_date->setText(QApplication::translate("MainWindow", "Press Refresh", Q_NULLPTR));
        btn_refresh->setText(QApplication::translate("MainWindow", "Refresh", Q_NULLPTR));
        btn_finishRepair->setText(QApplication::translate("MainWindow", "Finish Repair", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Orders", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Users", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
