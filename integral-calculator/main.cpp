#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("/Users/yakiv/Desktop/integral-calculator/integral-calculator/images/calculator_icon.png"));

    MainWindow w;
    w.setWindowTitle("Calculator");
    w.show();
    return a.exec();
}
