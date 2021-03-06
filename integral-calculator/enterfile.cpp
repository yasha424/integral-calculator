#include "enterfile.h"
#include "ui_enterfile.h"

EnterFile::EnterFile(QWidget *parent, double lower, double upper, int ind) :
    QDialog(parent),
    ui(new Ui::EnterFile)
{
    ui->setupUi(this);
    setWindowTitle("Enter File name");
    a = lower;
    b = upper;
    index = ind;
    r = NULL;
}

EnterFile::~EnterFile()
{
    delete ui;

    if (r){
        delete r;
    }
}

std::string EnterFile::before_equal(std::string str){
    size_t i = 0;
    while (str[i] != '=' && i < str.size()){
        i++;
    }
    return str.substr(0, i-1);
}

//перевіряє чи файл можливо відкрити та чи вираз у ньому є правильним
void EnterFile::on_pushButton_clicked()
{
    file_name = ui->line->text().toStdString();
    if (file_name.size() != 0 && file_name.compare(file_name.size() - 4, 4, ".txt") == 0 && check_file(file_name)){
        std::ifstream in(file_name);
        getline(in, expression);
        expression = before_equal(expression);
        if (check_expression(expression)){
            if (expression[0] == '-'){
                expression = "0" + expression;
            }
            for (size_t i = 0; i < expression.size()-1; i++){
                if (expression[i] == '(' && expression[i+1] == '-'){
                    expression.insert(i+1, "0");
                }
            }

            r = new Result(this, expression, a, b, index);
            r->setWindowTitle("Result");
            r->setModal(true);
            r->show();
            this->close();
        } else {
            QApplication::beep();
        }
    } else {
        QApplication::beep();
    }
}


bool EnterFile::check_file(std::string str){
    std::ifstream in(str);

    if (in) {
        in.close();
        return true;
    }

    return false;
}


//перевірка на те, чи формула у файлі є валідною
bool EnterFile::check_expression(std::string str){
    int brackets = 0;
    bool brack_possible = true;
    bool close_brack_possible = false;
    bool op_possible = false;
    bool x = false;
    bool dot = false;
    bool is_minus_possible = true;
    for (size_t i = 0; i < str.size(); i++){
//        std::cout << str[i] << std::endl;
        if (str[i] == '(' && brack_possible){
            brackets++;
            is_minus_possible = true;
            close_brack_possible = true;
            op_possible = false;
            x = false;
        } else if (str[i] == ')' && close_brack_possible){
            brackets--;
            is_minus_possible = true;
            brack_possible = false;
            op_possible = true;
            x = true;
        } else if (is_operator(str[i]) && i != 0 && op_possible){
            brack_possible = true;
            is_minus_possible = false;
            close_brack_possible = false;
            op_possible = false;
            x = false;
        } else if (str[i] == 'p' && str[i+1] == 'i'){
            i++;
            close_brack_possible = true;
            is_minus_possible = true;
            op_possible = true;
        } else if (str[i] == 'x' && !x){
            x = true;
            op_possible = true;
            close_brack_possible = true;
            is_minus_possible = true;
            brack_possible = false;
        } else if (str[i] == '-' && is_minus_possible) {
            x = false;
            is_minus_possible = false;
            brack_possible = true;
            close_brack_possible = false;
            op_possible = false;
            op_possible = false;
        }else if (isdigit(str[i]) && !x){
            op_possible = true;
            close_brack_possible = true;
            x = false;
            while ((!is_operator(str[i]) && str[i] != 'x' && str[i] != 'p' && str[i] != ')') && i < str.size()){
                if (!isdigit(str[i]) && str[i] != '.'){
                    return false;
                } else if (str[i] == '.' && dot){
                    return false;
                }
                i++;
            }
            i--;
        } else {
            return false;
        }
        if (brackets < 0){
            return false;
        }
    }
    return (brackets == 0 && op_possible);
}

//перевірка чи є символ оператором
bool EnterFile::is_operator(char ch){

    if (ch == '*' || ch == '/' || ch == '+' ||
            ch == '-' || ch == '^'){
        return true;
    }
    return false;
}
