#ifndef RESULT_H
#define RESULT_H

#pragma once
#include <QDialog>
#include <string>
#include "expression.h"
#include "tree.h"

namespace Ui {
class Result;
}

class Result : public QDialog
{
    Q_OBJECT

public:
    explicit Result(QWidget *parent = nullptr, std::string str = "", double upper = 0, double lower = 0, int index = 0);
    ~Result();

private slots:
    void test();

    void make_graph();

private:
    Ui::Result *ui;
    Expression *expression;
    double a, b;
    Tree *tree;
};

#endif // RESULT_H
