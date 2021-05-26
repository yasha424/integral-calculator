#include <QApplication>
#include <QLabel>

#include <iostream>
#include <unistd.h>

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    QLabel *label = new QLabel("");
    label->setWindowTitle("Integral - Calculator");
    label->resize(600, 400);

    label->show();

    return app.exec();
}
