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
}

EnterFile::~EnterFile()
{
    delete ui;
}

void EnterFile::on_pushButton_clicked()
{
    file_name = ui->line->text().toStdString();
    if (file_name.compare(file_name.size() - 3, 3, "txt") == 0 && check_file(file_name)){
        std::ifstream in(file_name);
        getline(in, expression);
//        std::cout << "ok" << std::endl;

        if (check_expression(expression)){
            std::cout << expression << std::endl;
            r = new Result(this, expression, a, b, index);
            r->setWindowTitle("Result");
            r->setModal(true);
            r->show();
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

bool EnterFile::check_expression(std::string str){
    int brackets = 0;
    bool brack_possible = true;
    bool close_brack_possible = false;
    bool op_possible = false;
    bool x = false;
    bool dot = false;
    for (size_t i = 0; i < str.size(); i++){
//        std::cout << str[i];
        if (str[i] == '(' && brack_possible){
            brackets++;
            close_brack_possible = true;
            op_possible = false;
            x = false;
        } else if (str[i] == ')' && close_brack_possible){
            brackets--;
            brack_possible = false;
            op_possible = true;
            x = true;
        } else if (is_operator(str[i]) && i != 0 && op_possible){
//            std::cout << "operator" << std::endl;
            brack_possible = true;
            close_brack_possible = false;
            op_possible = false;
            x = false;
        } else if (str[i] == 'p' && str[i+1] == 'i'){
            i++;
            close_brack_possible = true;
            op_possible = true;
        } else if (str[i] == 'x' && !x){
            x = true;
            op_possible = true;
            close_brack_possible = true;
            brack_possible = false;
        } else if (isdigit(str[i]) && !x){
            op_possible = true;
            close_brack_possible = true;
            x = false;
            while ((!is_operator(str[i]) && str[i] != 'x' && str[i] != 'p' && str[i] != ')') && i < str.size()){
                if (!isdigit(str[i]) && str[i] != '.'){
                    std::cout << str[i] << std::endl;
                    return false;
                } else if (str[i] == '.' && dot){
                    return false;
                }
                i++;
            }
        } else {
               std::cout << "false\n";
            return false;
        }
        if (brackets < 0){
//            std::cout << brack_possible << std::endl;
            return false;
        }
//        std::cout << x << std::endl;
    }
//    std::cout << std::endl << brackets << std::endl;
    return brackets == 0;
}

bool EnterFile::is_operator(char ch){
//    std::cout << ch << std::endl;

    if (ch == '*' || ch == '/' || ch == '+' ||
            ch == '-' || ch == '^'){
//        std::cout << "aaaaaaaaaaa" << std::endl;
        return true;
    }
    return false;
}

