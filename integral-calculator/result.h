#ifndef RESULT_H
#define RESULT_H

#pragma once
#include <QDialog>
#include <string>
#include <stdexcept>
#include <float.h>
#include "expression.h"
#include "tree.h"
#include "evaluation.h"
#include "savefile.h"

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

    void on_pushButton_clicked();

    void check_bounds();

    void undefined();

private:
    Ui::Result *ui;
    saveFile *s;
    Expression *expression;  // клас виразу
    double a, b; // межі
    Tree *tree; // дерево виразу
    double result; // результат
    bool defined; // інформація про тн, чи інтеграл визначений
    size_t depth, calls; // глибина рекурсіх та к-ість розбиття графіку

};

#endif // RESULT_H
