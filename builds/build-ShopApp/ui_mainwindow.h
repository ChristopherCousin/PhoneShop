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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLogin;
    QAction *actionLog_out;
    QAction *actionExit;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_6;
    QLineEdit *lineEdit_2;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *btn_findOrder;
    QLabel *statusOfOrderLabel;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *result_label;
    QLabel *label_client1;
    QLabel *label_client2;
    QLabel *label_client3;
    QLabel *label_client3_2;
    QWidget *tab_3;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QPushButton *btn_login;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_11;
    QWidget *tab_2;
    QPushButton *btn_newRepair;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label_4;
    QComboBox *comboBox_2;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_price;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(518, 461);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionLogin = new QAction(MainWindow);
        actionLogin->setObjectName(QStringLiteral("actionLogin"));
        actionLog_out = new QAction(MainWindow);
        actionLog_out->setObjectName(QStringLiteral("actionLog_out"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tab->setEnabled(true);
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 31, 81, 31));
        QFont font;
        font.setPointSize(13);
        label_6->setFont(font);
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 32, 351, 32));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 10, 471, 111));
        label_7->setStyleSheet(QLatin1String("QLabel {\n"
"border: 1px solid #CBC8C8;\n"
"border-radius: 15px;\n"
"}"));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 0, 71, 18));
        label_8->setStyleSheet(QLatin1String("QLabel{\n"
"background: solid black;\n"
"color: white;\n"
"}"));
        btn_findOrder = new QPushButton(tab);
        btn_findOrder->setObjectName(QStringLiteral("btn_findOrder"));
        btn_findOrder->setGeometry(QRect(170, 72, 221, 34));
        btn_findOrder->setFont(font);
        statusOfOrderLabel = new QLabel(tab);
        statusOfOrderLabel->setObjectName(QStringLiteral("statusOfOrderLabel"));
        statusOfOrderLabel->setGeometry(QRect(10, 140, 471, 201));
        statusOfOrderLabel->setStyleSheet(QLatin1String("QLabel {\n"
"border: 1px solid #CBC8C8;\n"
"border-radius: 15px;\n"
"}"));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 130, 81, 18));
        label_10->setStyleSheet(QLatin1String("QLabel{\n"
"background: solid black;\n"
"color: white;\n"
"}"));
        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(30, 170, 141, 18));
        label_12->setFont(font);
        result_label = new QLabel(tab);
        result_label->setObjectName(QStringLiteral("result_label"));
        result_label->setGeometry(QRect(160, 164, 301, 31));
        QFont font1;
        font1.setPointSize(15);
        result_label->setFont(font1);
        result_label->setStyleSheet(QStringLiteral(""));
        label_client1 = new QLabel(tab);
        label_client1->setObjectName(QStringLiteral("label_client1"));
        label_client1->setGeometry(QRect(30, 200, 141, 18));
        label_client1->setFont(font);
        label_client2 = new QLabel(tab);
        label_client2->setObjectName(QStringLiteral("label_client2"));
        label_client2->setGeometry(QRect(30, 230, 141, 18));
        label_client2->setFont(font);
        label_client3 = new QLabel(tab);
        label_client3->setObjectName(QStringLiteral("label_client3"));
        label_client3->setGeometry(QRect(30, 261, 141, 18));
        label_client3->setFont(font);
        label_client3_2 = new QLabel(tab);
        label_client3_2->setObjectName(QStringLiteral("label_client3_2"));
        label_client3_2->setGeometry(QRect(30, 294, 61, 18));
        label_client3_2->setFont(font);
        tabWidget->addTab(tab, QString());
        statusOfOrderLabel->raise();
        label_7->raise();
        label_6->raise();
        lineEdit_2->raise();
        label_8->raise();
        btn_findOrder->raise();
        label_10->raise();
        label_12->raise();
        result_label->raise();
        label_client1->raise();
        label_client2->raise();
        label_client3->raise();
        label_client3_2->raise();
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        lineEdit_username = new QLineEdit(tab_3);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));
        lineEdit_username->setGeometry(QRect(140, 80, 251, 32));
        lineEdit_password = new QLineEdit(tab_3);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(140, 130, 251, 32));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        btn_login = new QPushButton(tab_3);
        btn_login->setObjectName(QStringLiteral("btn_login"));
        btn_login->setGeometry(QRect(200, 190, 121, 41));
        btn_login->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/Resources/login.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_login->setIcon(icon);
        btn_login->setIconSize(QSize(32, 32));
        pushButton_2 = new QPushButton(tab_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 20, 91, 41));
        pushButton_2->setFont(font);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/Resources/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(36, 36));
        pushButton_3 = new QPushButton(tab_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(100, 80, 41, 31));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton {\n"
"    border-style: outset;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Resources/Resources/username.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(32, 32));
        pushButton_4 = new QPushButton(tab_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(100, 130, 41, 31));
        pushButton_4->setStyleSheet(QLatin1String("QPushButton {\n"
"    border-style: outset;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Resources/Resources/password.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon3);
        pushButton_4->setIconSize(QSize(32, 32));
        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 10, 481, 241));
        label_11->setStyleSheet(QLatin1String("QLabel {\n"
"border: 1px solid #CBC8C8;\n"
"border-radius: 15px;\n"
"}"));
        tabWidget->addTab(tab_3, QString());
        label_11->raise();
        lineEdit_username->raise();
        lineEdit_password->raise();
        btn_login->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        btn_newRepair = new QPushButton(tab_2);
        btn_newRepair->setObjectName(QStringLiteral("btn_newRepair"));
        btn_newRepair->setGeometry(QRect(170, 200, 151, 41));
        QFont font2;
        font2.setPointSize(14);
        btn_newRepair->setFont(font2);
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 60, 91, 18));
        label_3->setFont(font2);
        comboBox = new QComboBox(tab_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(160, 55, 311, 32));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 100, 131, 21));
        QFont font3;
        font3.setPointSize(12);
        label_4->setFont(font3);
        comboBox_2 = new QComboBox(tab_2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(160, 96, 311, 32));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 471, 151));
        label->setStyleSheet(QLatin1String("QLabel {\n"
"border: 1px solid #CBC8C8;\n"
"border-radius: 15px;\n"
"}"));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 20, 71, 18));
        label_5->setStyleSheet(QLatin1String("QLabel{\n"
"background: solid black;\n"
"color: white;\n"
"}"));
        label_price = new QLabel(tab_2);
        label_price->setObjectName(QStringLiteral("label_price"));
        label_price->setGeometry(QRect(20, 140, 441, 20));
        label_price->setFont(font2);
        tabWidget->addTab(tab_2, QString());
        label->raise();
        btn_newRepair->raise();
        label_3->raise();
        comboBox->raise();
        label_4->raise();
        comboBox_2->raise();
        label_5->raise();
        label_price->raise();

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 518, 30));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLogin);
        menuFile->addAction(actionLog_out);
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionLogin->setText(QApplication::translate("MainWindow", "&Login", Q_NULLPTR));
        actionLog_out->setText(QApplication::translate("MainWindow", "Log &out", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "&Exit", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Order ID:", Q_NULLPTR));
        label_7->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "Find Orders", Q_NULLPTR));
        btn_findOrder->setText(QApplication::translate("MainWindow", "Find Order", Q_NULLPTR));
        statusOfOrderLabel->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "Order Details", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Status of Order:", Q_NULLPTR));
        result_label->setText(QString());
        label_client1->setText(QApplication::translate("MainWindow", "Client Name:", Q_NULLPTR));
        label_client2->setText(QApplication::translate("MainWindow", "E-mail:", Q_NULLPTR));
        label_client3->setText(QApplication::translate("MainWindow", "Repair Name:", Q_NULLPTR));
        label_client3_2->setText(QApplication::translate("MainWindow", "Price:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Orders", Q_NULLPTR));
        btn_login->setText(QApplication::translate("MainWindow", "Login", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Back", Q_NULLPTR));
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        label_11->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Login", Q_NULLPTR));
        btn_newRepair->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Phone:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Available repairs:", Q_NULLPTR));
        label->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Send repair", Q_NULLPTR));
        label_price->setText(QApplication::translate("MainWindow", "Price:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "New repair", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "Fi&le", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
