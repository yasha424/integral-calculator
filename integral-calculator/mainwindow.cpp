#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_zero_clicked()
{
    if(ui->label->text() != "0"){
        ui->label->setText(ui->label->text() + "0");
    }
}

void MainWindow::on_one_clicked()
{
    ui->label->setText(ui->label->text() + "1");
}


void MainWindow::on_two_clicked()
{
    ui->label->setText(ui->label->text() + "2");
}


void MainWindow::on_three_clicked()
{
    ui->label->setText(ui->label->text() + "3");
}


void MainWindow::on_four_clicked()
{
    ui->label->setText(ui->label->text() + "4");
}


void MainWindow::on_five_clicked()
{
    ui->label->setText(ui->label->text() + "5");
}


void MainWindow::on_six_clicked()
{
    ui->label->setText(ui->label->text() + "6");
}


void MainWindow::on_seven_clicked()
{
    ui->label->setText(ui->label->text() + "7");
}


void MainWindow::on_eight_clicked()
{
    ui->label->setText(ui->label->text() + "8");
}


void MainWindow::on_nine_clicked()
{
    ui->label->setText(ui->label->text() + "9");
}


void MainWindow::on_clear_clicked()
{
    ui->label->setText("0");
}


void MainWindow::on_equal_clicked()
{
    std::cout << ui->label->text().toStdString() << std::endl;
}


void MainWindow::on_plus_clicked()
{
    ui->label->setText("+");
}


void MainWindow::on_minus_clicked()
{
    ui->label->setText("-");
}


void MainWindow::on_divide_clicked()
{
    ui->label->setText("/");
}


void MainWindow::on_mult_clicked()
{
    ui->label->setText("*");
}


void MainWindow::on_openBracket_clicked()
{
    ui->label->setText("(");
}


void MainWindow::on_closeBracket_clicked()
{
    ui->label->setText(")");
}


void MainWindow::on_sqrt_clicked()
{
    ui->label->setText("√");
}

