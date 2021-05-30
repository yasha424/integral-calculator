#ifndef RESULT_H
#define RESULT_H

#include <QDialog>
#include <string>
#include "expression.h"

namespace Ui {
class Result;
}

class Result : public QDialog
{
    Q_OBJECT

public:
    explicit Result(QWidget *parent = nullptr, std::string str = "", double upper = 0, double lower = 0);
    ~Result();

private slots:
    void test();

    void make_graph();

private:
    Ui::Result *ui;
    Expression *expression;
    double a, b;
};

#endif // RESULT_H
