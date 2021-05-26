#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    brackets = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::is_operation_possible(){
    return !(ui->label->text().endsWith("+") || ui->label->text().endsWith("√") ||
             ui->label->text().endsWith("-") || ui->label->text().endsWith("*") ||
             ui->label->text().endsWith("/"));
}

bool MainWindow::is_bracket_possible(){
    return (ui->label->text().endsWith("*") || ui->label->text().endsWith("/") ||
            ui->label->text().endsWith("+") || ui->label->text().endsWith("-") ||
            ui->label->text().endsWith("√"));
}

void MainWindow::on_zero_clicked()
{
    if(ui->label->text() != "0" && !ui->label->text().endsWith(")")){
        ui->label->setText(ui->label->text() + "0");
    } else if(ui->label->text().endsWith(")")){
        QApplication::beep();
    }
}

void MainWindow::on_one_clicked()
{
    if(ui->label->text() != "0" && !ui->label->text().endsWith(")")){
        ui->label->setText(ui->label->text() + "1");
    } else if(ui->label->text().endsWith(")")){
        QApplication::beep();
    } else{
        ui->label->setText("1");
    }
}


void MainWindow::on_two_clicked()
{
    if(ui->label->text() != "0" && !ui->label->text().endsWith(")")){
        ui->label->setText(ui->label->text() + "2");
    } else if(ui->label->text().endsWith(")")){
        QApplication::beep();
    } else{
        ui->label->setText("2");
    }
}


void MainWindow::on_three_clicked()
{
    if(ui->label->text() != "0" && !ui->label->text().endsWith(")")){
        ui->label->setText(ui->label->text() + "3");
    } else if(ui->label->text().endsWith(")")){
        QApplication::beep();
    } else{
        ui->label->setText("3");
    }
}


void MainWindow::on_four_clicked()
{
    if(ui->label->text() != "0" && !ui->label->text().endsWith(")")){
        ui->label->setText(ui->label->text() + "4");
    } else if(ui->label->text().endsWith(")")){
        QApplication::beep();
    } else{
        ui->label->setText("4");
    }
}


void MainWindow::on_five_clicked()
{
    if(ui->label->text() != "0" && !ui->label->text().endsWith(")")){
        ui->label->setText(ui->label->text() + "5");
    } else if(ui->label->text().endsWith(")")){
        QApplication::beep();
    } else{
        ui->label->setText("5");
    }
}


void MainWindow::on_six_clicked()
{
    if(ui->label->text() != "0" && !ui->label->text().endsWith(")")){
        ui->label->setText(ui->label->text() + "6");
    } else if(ui->label->text().endsWith(")")){
        QApplication::beep();
    } else{
        ui->label->setText("6");
    }
}

void MainWindow::on_seven_clicked()
{
    if(ui->label->text() != "0" && !ui->label->text().endsWith(")")){
        ui->label->setText(ui->label->text() + "7");
    } else if(ui->label->text().endsWith(")")){
        QApplication::beep();
    } else{
        ui->label->setText("7");
    }
}

void MainWindow::on_eight_clicked()
{
    if(ui->label->text() != "0" && !ui->label->text().endsWith(")")){
        ui->label->setText(ui->label->text() + "8");
    } else if(ui->label->text().endsWith(")")){
        QApplication::beep();
    } else{
        ui->label->setText("8");
    }
}

void MainWindow::on_nine_clicked()
{
    if(ui->label->text() != "0" && !ui->label->text().endsWith(")")){
        ui->label->setText(ui->label->text() + "9");
    } else if(ui->label->text().endsWith(")")){
        QApplication::beep();
    } else{
        ui->label->setText("9");
    }
}

void MainWindow::on_clear_clicked()
{
    ui->label->setText("0");
}

void MainWindow::on_plus_clicked()
{
    if(ui->label->text() != "0" && is_operation_possible()){
        ui->label->setText(ui->label->text() + "+");
    } else{
        QApplication::beep();
    }
}


void MainWindow::on_minus_clicked()
{
    if(ui->label->text() != "0" && is_operation_possible()){
        ui->label->setText(ui->label->text() + "-");
    } else{
        QApplication::beep();
    }
}


void MainWindow::on_divide_clicked()
{
    if(ui->label->text() != "0" && is_operation_possible()){
        ui->label->setText(ui->label->text() + "/");
    } else{
        QApplication::beep();
    }
}


void MainWindow::on_mult_clicked()
{
    if(ui->label->text() != "0" && is_operation_possible()){
        ui->label->setText(ui->label->text() + "*");
    } else{
        QApplication::beep();
    }
}


void MainWindow::on_openBracket_clicked()
{
    if(is_bracket_possible() || ui->label->text() == "0" || ui->label->text().endsWith("(")){
        if (ui->label->text() != "0"){
            ui->label->setText(ui->label->text() + "(");
        } else{
            ui->label->setText("(");
        }
        brackets++;
    } else{
        QApplication::beep();
    }
}


void MainWindow::on_closeBracket_clicked()
{
    if(!is_bracket_possible()){
        if(brackets > 0){
            ui->label->setText(ui->label->text() + ")");
            brackets--;
        } else{
            QApplication::beep();
        }
    } else{
        QApplication::beep();
    }
}


void MainWindow::on_sqrt_clicked()
{
    ui->label->setText("√");
}



void MainWindow::on_equal_clicked()
{
    std::cout << ui->label->text().toStdString() << std::endl;
}

void MainWindow::on_delet_clicked()
{
    std::cout << ui->label->text().size() << std::endl;
}

