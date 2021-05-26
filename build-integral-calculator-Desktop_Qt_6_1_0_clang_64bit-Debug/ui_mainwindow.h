/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *zero;
    QPushButton *dot;
    QPushButton *equal;
    QPushButton *six;
    QPushButton *five;
    QPushButton *four;
    QPushButton *three;
    QPushButton *two;
    QPushButton *one;
    QPushButton *nine;
    QPushButton *eight;
    QPushButton *seven;
    QPushButton *mult;
    QPushButton *minus;
    QPushButton *plus;
    QPushButton *divide;
    QPushButton *closeBracket;
    QPushButton *openBracket;
    QPushButton *clear;
    QLabel *label;
    QPushButton *delet;
    QPushButton *sqrt;
    QPushButton *x_but;
    QStatusBar *statusbar;
    QButtonGroup *buttonGroup_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(430, 492);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        zero = new QPushButton(centralwidget);
        buttonGroup_2 = new QButtonGroup(MainWindow);
        buttonGroup_2->setObjectName(QString::fromUtf8("buttonGroup_2"));
        buttonGroup_2->addButton(zero);
        zero->setObjectName(QString::fromUtf8("zero"));
        zero->setGeometry(QRect(70, 350, 130, 60));
        QFont font;
        font.setPointSize(24);
        zero->setFont(font);
        zero->setMouseTracking(true);
        zero->setTabletTracking(true);
        dot = new QPushButton(centralwidget);
        buttonGroup_2->addButton(dot);
        dot->setObjectName(QString::fromUtf8("dot"));
        dot->setGeometry(QRect(210, 350, 60, 60));
        dot->setFont(font);
        dot->setMouseTracking(true);
        dot->setTabletTracking(true);
        equal = new QPushButton(centralwidget);
        buttonGroup_2->addButton(equal);
        equal->setObjectName(QString::fromUtf8("equal"));
        equal->setGeometry(QRect(280, 350, 60, 60));
        equal->setFont(font);
        equal->setMouseTracking(true);
        equal->setTabletTracking(true);
        six = new QPushButton(centralwidget);
        buttonGroup_2->addButton(six);
        six->setObjectName(QString::fromUtf8("six"));
        six->setGeometry(QRect(210, 210, 60, 60));
        six->setFont(font);
        six->setMouseTracking(true);
        six->setTabletTracking(true);
        five = new QPushButton(centralwidget);
        buttonGroup_2->addButton(five);
        five->setObjectName(QString::fromUtf8("five"));
        five->setGeometry(QRect(140, 210, 60, 60));
        five->setFont(font);
        five->setMouseTracking(true);
        five->setTabletTracking(true);
        four = new QPushButton(centralwidget);
        buttonGroup_2->addButton(four);
        four->setObjectName(QString::fromUtf8("four"));
        four->setGeometry(QRect(70, 210, 60, 60));
        four->setFont(font);
        four->setMouseTracking(true);
        four->setTabletTracking(true);
        three = new QPushButton(centralwidget);
        buttonGroup_2->addButton(three);
        three->setObjectName(QString::fromUtf8("three"));
        three->setGeometry(QRect(210, 280, 60, 60));
        three->setFont(font);
        three->setMouseTracking(true);
        three->setTabletTracking(true);
        two = new QPushButton(centralwidget);
        buttonGroup_2->addButton(two);
        two->setObjectName(QString::fromUtf8("two"));
        two->setGeometry(QRect(140, 280, 60, 60));
        two->setFont(font);
        two->setMouseTracking(true);
        two->setTabletTracking(true);
        one = new QPushButton(centralwidget);
        buttonGroup_2->addButton(one);
        one->setObjectName(QString::fromUtf8("one"));
        one->setGeometry(QRect(70, 280, 60, 60));
        one->setFont(font);
        one->setMouseTracking(true);
        one->setTabletTracking(true);
        nine = new QPushButton(centralwidget);
        buttonGroup_2->addButton(nine);
        nine->setObjectName(QString::fromUtf8("nine"));
        nine->setGeometry(QRect(210, 140, 60, 60));
        nine->setFont(font);
        nine->setMouseTracking(true);
        nine->setTabletTracking(true);
        eight = new QPushButton(centralwidget);
        buttonGroup_2->addButton(eight);
        eight->setObjectName(QString::fromUtf8("eight"));
        eight->setGeometry(QRect(140, 140, 60, 60));
        eight->setFont(font);
        eight->setMouseTracking(true);
        eight->setTabletTracking(true);
        seven = new QPushButton(centralwidget);
        buttonGroup_2->addButton(seven);
        seven->setObjectName(QString::fromUtf8("seven"));
        seven->setGeometry(QRect(70, 140, 60, 60));
        seven->setFont(font);
        seven->setMouseTracking(true);
        seven->setTabletTracking(true);
        mult = new QPushButton(centralwidget);
        buttonGroup_2->addButton(mult);
        mult->setObjectName(QString::fromUtf8("mult"));
        mult->setGeometry(QRect(280, 70, 60, 60));
        mult->setFont(font);
        mult->setMouseTracking(true);
        mult->setTabletTracking(true);
        minus = new QPushButton(centralwidget);
        buttonGroup_2->addButton(minus);
        minus->setObjectName(QString::fromUtf8("minus"));
        minus->setGeometry(QRect(280, 210, 60, 60));
        minus->setFont(font);
        minus->setMouseTracking(true);
        minus->setTabletTracking(true);
        plus = new QPushButton(centralwidget);
        buttonGroup_2->addButton(plus);
        plus->setObjectName(QString::fromUtf8("plus"));
        plus->setGeometry(QRect(280, 280, 60, 60));
        plus->setFont(font);
        plus->setMouseTracking(true);
        plus->setTabletTracking(true);
        divide = new QPushButton(centralwidget);
        buttonGroup_2->addButton(divide);
        divide->setObjectName(QString::fromUtf8("divide"));
        divide->setGeometry(QRect(280, 140, 60, 60));
        divide->setFont(font);
        divide->setMouseTracking(true);
        divide->setTabletTracking(true);
        closeBracket = new QPushButton(centralwidget);
        buttonGroup_2->addButton(closeBracket);
        closeBracket->setObjectName(QString::fromUtf8("closeBracket"));
        closeBracket->setGeometry(QRect(210, 70, 60, 60));
        closeBracket->setFont(font);
        closeBracket->setMouseTracking(true);
        closeBracket->setTabletTracking(true);
        openBracket = new QPushButton(centralwidget);
        buttonGroup_2->addButton(openBracket);
        openBracket->setObjectName(QString::fromUtf8("openBracket"));
        openBracket->setGeometry(QRect(140, 70, 60, 60));
        openBracket->setFont(font);
        openBracket->setMouseTracking(true);
        openBracket->setTabletTracking(true);
        clear = new QPushButton(centralwidget);
        buttonGroup_2->addButton(clear);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setGeometry(QRect(70, 70, 60, 60));
        clear->setFont(font);
        clear->setMouseTracking(true);
        clear->setTabletTracking(true);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 10, 341, 51));
        label->setFont(font);
        label->setMouseTracking(true);
        label->setTabletTracking(true);
        label->setLayoutDirection(Qt::RightToLeft);
        label->setAutoFillBackground(true);
        delet = new QPushButton(centralwidget);
        buttonGroup_2->addButton(delet);
        delet->setObjectName(QString::fromUtf8("delet"));
        delet->setGeometry(QRect(350, 350, 60, 60));
        delet->setFont(font);
        delet->setMouseTracking(true);
        delet->setTabletTracking(true);
        sqrt = new QPushButton(centralwidget);
        sqrt->setObjectName(QString::fromUtf8("sqrt"));
        sqrt->setGeometry(QRect(350, 280, 60, 60));
        sqrt->setFont(font);
        sqrt->setMouseTracking(true);
        sqrt->setTabletTracking(true);
        x_but = new QPushButton(centralwidget);
        x_but->setObjectName(QString::fromUtf8("x_but"));
        x_but->setGeometry(QRect(350, 210, 60, 60));
        x_but->setFont(font);
        x_but->setMouseTracking(true);
        x_but->setTabletTracking(true);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        zero->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        equal->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        six->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        five->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        four->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        three->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        two->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        one->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        nine->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        eight->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        seven->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        mult->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        divide->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        closeBracket->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        openBracket->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        clear->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        delet->setText(QCoreApplication::translate("MainWindow", "\342\214\253", nullptr));
        sqrt->setText(QCoreApplication::translate("MainWindow", "\342\210\232", nullptr));
        x_but->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
