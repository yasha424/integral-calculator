#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "result.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    brackets = 0;
    dot = false;
    QPixmap q("/Users/yakiv/Desktop/integral-calculator/integral-calculator/images/integral-white.png");
    ui->integral_sign->setPixmap(q);
//    ui->label->setTextInteractionFlags(Qt::TextSelectableByMouse);
}

MainWindow::~MainWindow() {
    delete ui;
}

bool MainWindow::is_operation_possible() {
    return !(ui->label->text().endsWith("+") || ui->label->text().endsWith("√") ||
             ui->label->text().endsWith("-") || ui->label->text().endsWith("*") ||
             ui->label->text().endsWith("/") || ui->label->text().endsWith(".") ||
             ui->label->text().endsWith("("));
}

bool MainWindow::is_bracket_possible() {
    return (ui->label->text().endsWith("*") || ui->label->text().endsWith("/") ||
            ui->label->text().endsWith("+") || ui->label->text().endsWith("-") ||
            ui->label->text().endsWith("√") || ui->label->text().endsWith("^"));
}

bool MainWindow::is_x_possible() {
    return (ui->label->text().endsWith("*") || ui->label->text().endsWith("/") ||
            ui->label->text().endsWith("+") || ui->label->text().endsWith("-") ||
            ui->label->text().endsWith("√") || ui->label->text().endsWith("(") ||
            ui->label->text().endsWith("^"));
}

bool MainWindow::is_pow_possible() {
    return (ui->label->text().endsWith("0") || ui->label->text().endsWith("1") ||
            ui->label->text().endsWith("2") || ui->label->text().endsWith("3") ||
            ui->label->text().endsWith("4") || ui->label->text().endsWith("5") ||
            ui->label->text().endsWith("6") || ui->label->text().endsWith("7") ||
            ui->label->text().endsWith("8") || ui->label->text().endsWith("9") ||
            ui->label->text().endsWith("x") || ui->label->text().endsWith(")"));
}

bool MainWindow::is_number(std::string str) {
    for(size_t i = 0; i < str.size(); i++){
        if(!std::isdigit(str[i]))
            return false;
    }
    if (str.size() == 0) return false;
    return true;
}

bool MainWindow::is_digit_possible() {
    return (ui->label->text() != "0" && !ui->label->text().endsWith(")") && !ui->label->text().endsWith("x"));
}

void MainWindow::on_zero_clicked() {
    if(is_digit_possible()){
        ui->label->setText(ui->label->text() + "0");
    } else if(ui->label->text().endsWith(")") || ui->label->text().endsWith("x")){
        QApplication::beep();
    }
}

void MainWindow::on_one_clicked() {
    if(is_digit_possible()){
        ui->label->setText(ui->label->text() + "1");
    } else if(ui->label->text().endsWith(")") || ui->label->text().endsWith("x")){
        QApplication::beep();
    } else {
        ui->label->setText("1");
    }
}

void MainWindow::on_two_clicked() {
    if(is_digit_possible()){
        ui->label->setText(ui->label->text() + "2");
    } else if(ui->label->text().endsWith(")") || ui->label->text().endsWith("x")){
        QApplication::beep();
    } else {
        ui->label->setText("2");
    }
}

void MainWindow::on_three_clicked() {
    if(is_digit_possible()){
        ui->label->setText(ui->label->text() + "3");
    } else if(ui->label->text().endsWith(")") || ui->label->text().endsWith("x")){
        QApplication::beep();
    } else {
        ui->label->setText("3");
    }
}

void MainWindow::on_four_clicked() {
    if(is_digit_possible()){
        ui->label->setText(ui->label->text() + "4");
    } else if(ui->label->text().endsWith(")") || ui->label->text().endsWith("x")){
        QApplication::beep();
    } else {
        ui->label->setText("4");
    }
}

void MainWindow::on_five_clicked() {
    if(is_digit_possible()){
        ui->label->setText(ui->label->text() + "5");
    } else if(ui->label->text().endsWith(")") || ui->label->text().endsWith("x")){
        QApplication::beep();
    } else {
        ui->label->setText("5");
    }
}

void MainWindow::on_six_clicked() {
    if(is_digit_possible()){
        ui->label->setText(ui->label->text() + "6");
    } else if(ui->label->text().endsWith(")") || ui->label->text().endsWith("x")){
        QApplication::beep();
    } else {
        ui->label->setText("6");
    }
}

void MainWindow::on_seven_clicked() {
    if(is_digit_possible()){
        ui->label->setText(ui->label->text() + "7");
    } else if(ui->label->text().endsWith(")") || ui->label->text().endsWith("x")){
        QApplication::beep();
    } else {
        ui->label->setText("7");
    }
}

void MainWindow::on_eight_clicked() {
    if(is_digit_possible()){
        ui->label->setText(ui->label->text() + "8");
    } else if(ui->label->text().endsWith(")") || ui->label->text().endsWith("x")){
        QApplication::beep();
    } else {
        ui->label->setText("8");
    }
}

void MainWindow::on_nine_clicked() {
    if(is_digit_possible()){
        ui->label->setText(ui->label->text() + "9");
    } else if(ui->label->text().endsWith(")") || ui->label->text().endsWith("x")){
        QApplication::beep();
    } else {
        ui->label->setText("9");
    }
}

void MainWindow::on_clear_clicked() {
    ui->label->setText("0");
    dot = false;
    brackets = 0;
}

void MainWindow::on_delet_clicked() {
    if(!(ui->label->text().size() == 1 && ui->label->text() == "0")){
        if(ui->label->text().endsWith(".")){
            dot = false;
        } else if (ui->label->text().endsWith(")")){
            brackets++;
        } else if (ui->label->text().endsWith("(")){
            brackets--;
        }
        ui->label->setText(ui->label->text().remove(ui->label->text().size()-1, 1));
    }
    if(ui->label->text().size() == 0){
        ui->label->setText("0");
    }
}

void MainWindow::on_plus_clicked() {
    if(ui->label->text() != "0" && is_operation_possible()){
        ui->label->setText(ui->label->text() + "+");
        dot = false;
    } else {
        QApplication::beep();
    }
}

void MainWindow::on_minus_clicked() {
    if(ui->label->text() != "0" && is_operation_possible()){
        ui->label->setText(ui->label->text() + "-");
        dot = false;
    } else if (ui->label->text() == "0") {
        ui->label->setText("-");
    } else {
        QApplication::beep();
    }
}

void MainWindow::on_divide_clicked() {
    if(ui->label->text() != "0" && is_operation_possible()){
        ui->label->setText(ui->label->text() + "/");
        dot = false;
    } else {
        QApplication::beep();
    }
}

void MainWindow::on_mult_clicked() {
    if(ui->label->text() != "0" && is_operation_possible()){
        ui->label->setText(ui->label->text() + "*");
        dot = false;
    } else {
        QApplication::beep();
    }
}

void MainWindow::on_openBracket_clicked() {
    if(is_bracket_possible() || ui->label->text() == "0" || ui->label->text().endsWith("(")){
        if (ui->label->text() != "0"){
            ui->label->setText(ui->label->text() + "(");
        } else {
            ui->label->setText("(");
        }
        brackets++;
    } else {
        QApplication::beep();
    }
}

void MainWindow::on_closeBracket_clicked() {
    if(!is_bracket_possible() && !ui->label->text().endsWith(".")){
        if(brackets > 0){
            ui->label->setText(ui->label->text() + ")");
            brackets--;
        } else {
            QApplication::beep();
        }
    } else {
        QApplication::beep();
    }
}

void MainWindow::on_sqrt_clicked() {
    if(is_bracket_possible() || ui->label->text().endsWith("(")){
        ui->label->setText(ui->label->text() + "√");
        dot = false;
    } else if((ui->label->text() == "0" && ui->label->text().size() == 1)){
        ui->label->setText("√");
    } else {
        QApplication::beep();
    }
}

void MainWindow::on_dot_clicked() {
    if(!dot && is_operation_possible() && !ui->label->text().endsWith(")") && !ui->label->text().endsWith("x")){
        ui->label->setText(ui->label->text() + ".");
        dot = true;
    } else {
        QApplication::beep();
    }
}

void MainWindow::on_x_but_clicked() {
    if(is_x_possible()){
        ui->label->setText(ui->label->text() + "x");
    } else if(ui->label->text().endsWith("0") && ui->label->text().size() == 1){
        ui->label->setText("x");
    } else {
        QApplication::beep();
    }
}

void MainWindow::on_pow_clicked() {
    if(is_pow_possible() && !(ui->label->text().endsWith("0") && ui->label->text().size() == 1)){
        ui->label->setText(ui->label->text() + "^");
    } else {
        QApplication::beep();
    }
}



void MainWindow::on_clear_2_clicked() {
    ui->label->setText("0");
    dot = false;
    brackets = 0;
}

void MainWindow::on_equal_clicked() {
    std::string upper = ui->upper_bound->text().toStdString(),
                lower = ui->lower_bound->text().toStdString();
    if(brackets != 0 || !check_number(upper) || !check_number(lower) || !is_operation_possible()){
        QApplication::beep();
    } else {
        double a = stod(lower), b = stod(upper);
        std::string expression = ui->label->text().toStdString();

        r = new Result(this, expression, a, b, ui->choose->currentIndex());
        r->setModal(true);
        r->show();

//        this->hide();
    }
}

bool MainWindow::check_number(std::string str){
    int i = 0;
    if (str[0] == '-') {
        i++;
    }
    for ( ; i < str.size(); i++){
        if (!isdigit(str[i])){
            return false;
        }
    }
    return true;
}

