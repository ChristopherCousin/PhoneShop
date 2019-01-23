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
    QAction *actionAdd_Phone;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *btn_AddPhone;
    QComboBox *comboBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_Repairname;
    QLineEdit *lineEdit_Repairprice;
    QPushButton *btn_AddRepair;
    QPushButton *btn_deletePhone;
    QWidget *tab;
    QPushButton *btn_WriteXML;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(581, 498);
        actionAdd_Phone = new QAction(MainWindow);
        actionAdd_Phone->setObjectName(QStringLiteral("actionAdd_Phone"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 43, 61, 21));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(100, 40, 281, 32));
        btn_AddPhone = new QPushButton(tab_2);
        btn_AddPhone->setObjectName(QStringLiteral("btn_AddPhone"));
        btn_AddPhone->setGeometry(QRect(400, 36, 121, 41));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        btn_AddPhone->setFont(font1);
        btn_AddPhone->setStyleSheet(QStringLiteral(""));
        comboBox = new QComboBox(tab_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(180, 150, 311, 32));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 154, 141, 21));
        label_2->setFont(font);
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 21, 531, 71));
        label_3->setStyleSheet(QLatin1String("QLabel {\n"
"border: 1px solid #CBC8C8;\n"
"border-radius: 15px;\n"
"}"));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 120, 531, 251));
        label_4->setStyleSheet(QLatin1String("QLabel {\n"
"border: 1px solid #CBC8C8;\n"
"border-radius: 15px;\n"
"}"));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 11, 101, 18));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        label_5->setFont(font2);
        label_5->setStyleSheet(QLatin1String("QLabel{\n"
"background: solid black;\n"
"color: white;\n"
"}"));
        label_5->setWordWrap(false);
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 111, 171, 18));
        label_6->setFont(font2);
        label_6->setStyleSheet(QLatin1String("QLabel{\n"
"background: solid black;\n"
"color: white;\n"
"}"));
        label_6->setWordWrap(false);
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 220, 131, 21));
        label_7->setFont(font);
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(41, 265, 121, 21));
        label_8->setFont(font);
        lineEdit_Repairname = new QLineEdit(tab_2);
        lineEdit_Repairname->setObjectName(QStringLiteral("lineEdit_Repairname"));
        lineEdit_Repairname->setGeometry(QRect(174, 217, 321, 32));
        lineEdit_Repairprice = new QLineEdit(tab_2);
        lineEdit_Repairprice->setObjectName(QStringLiteral("lineEdit_Repairprice"));
        lineEdit_Repairprice->setGeometry(QRect(174, 261, 321, 32));
        btn_AddRepair = new QPushButton(tab_2);
        btn_AddRepair->setObjectName(QStringLiteral("btn_AddRepair"));
        btn_AddRepair->setGeometry(QRect(220, 310, 171, 41));
        btn_AddRepair->setFont(font1);
        btn_AddRepair->setStyleSheet(QStringLiteral(""));
        btn_deletePhone = new QPushButton(tab_2);
        btn_deletePhone->setObjectName(QStringLiteral("btn_deletePhone"));
        btn_deletePhone->setGeometry(QRect(420, 320, 71, 31));
        btn_deletePhone->setStyleSheet(QLatin1String("QPushButton {\n"
"color:red;\n"
"}"));
        tabWidget->addTab(tab_2, QString());
        label_3->raise();
        label_4->raise();
        label->raise();
        lineEdit->raise();
        btn_AddPhone->raise();
        comboBox->raise();
        label_2->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        lineEdit_Repairname->raise();
        lineEdit_Repairprice->raise();
        btn_AddRepair->raise();
        btn_deletePhone->raise();
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        btn_WriteXML = new QPushButton(tab);
        btn_WriteXML->setObjectName(QStringLiteral("btn_WriteXML"));
        btn_WriteXML->setGeometry(QRect(150, 230, 201, 51));
        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 581, 30));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionAdd_Phone);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionAdd_Phone->setText(QApplication::translate("MainWindow", "&Add Phone", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Name:", Q_NULLPTR));
        btn_AddPhone->setText(QApplication::translate("MainWindow", "ADD Phone", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Select Phone:", Q_NULLPTR));
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Add new Phone", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Add repair or delete phone", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Repair Name:", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Repair Price:", Q_NULLPTR));
        btn_AddRepair->setText(QApplication::translate("MainWindow", "Add Repair", Q_NULLPTR));
        btn_deletePhone->setText(QApplication::translate("MainWindow", "Delete", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Phones", Q_NULLPTR));
        btn_WriteXML->setText(QApplication::translate("MainWindow", "Write XML", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "XML", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "Fi&le", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
