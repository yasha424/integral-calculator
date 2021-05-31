#ifndef ENTERFILE_H
#define ENTERFILE_H

#pragma once
#include <QDialog>
#include <string>
#include <fstream>
#include <iostream>
#include "result.h"
namespace Ui {
class EnterFile;
}

class EnterFile : public QDialog
{
    Q_OBJECT

public:
    explicit EnterFile(QWidget *parent = nullptr, double a = 0, double b = 0, int index = 0);
    ~EnterFile();
    bool check_file(std::string);
    bool check_expression(std::string);
    bool is_operator(char);

private slots:
    void on_pushButton_clicked();

private:
    Ui::EnterFile *ui;
    double a, b;
    int index;
    std::string file_name, expression;
    Result *r;

};

#endif // ENTERFILE_H
