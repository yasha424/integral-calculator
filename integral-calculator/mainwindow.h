#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#include <QMainWindow>
#include <QWidget>
#include "result.h"
#include "enterfile.h"

#include <iostream>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_zero_clicked();

    void on_one_clicked();

    void on_two_clicked();

    void on_three_clicked();

    void on_four_clicked();

    void on_five_clicked();

    void on_six_clicked();

    void on_seven_clicked();

    void on_eight_clicked();

    void on_nine_clicked();

    void on_clear_clicked();

    void on_equal_clicked();

    void on_plus_clicked();

    void on_minus_clicked();

    void on_divide_clicked();

    void on_mult_clicked();

    void on_openBracket_clicked();

    void on_closeBracket_clicked();

    void on_delet_clicked();

    bool is_operation_possible();

    bool is_bracket_possible();

    void on_dot_clicked();

    void on_x_but_clicked();

    bool is_x_possible();

    bool is_digit_possible();

    void on_pow_clicked();

    bool is_pow_possible();

    void on_clear_2_clicked();

    bool is_number(std::string);

    bool check_number(std::string);

    void on_pi_clicked();

    void check_length();

    void on_file_clicked();

private:
    Ui::MainWindow *ui;
    Result *r;
    EnterFile *enter;

    int brackets; // к-іст ьвідкритих дужок
    bool dot; // чи поставлена в числі крапка (двох крапок в одному числі бути не може)
    int font_size; // розмір шрифту
};
#endif // MAINWINDOW_H
