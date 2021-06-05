#include "savefile.h"
#include "ui_savefile.h"

saveFile::saveFile(QWidget *parent, std::string res, std::string exp, int divides, int depth, double low, double up) :
    QDialog(parent),
    ui(new Ui::saveFile)
{
    ui->setupUi(this);
    expression = exp;
    result = res;
    this->divides = divides;
    this->depth = depth;
    a = low;
    b = up;
}

saveFile::~saveFile()
{
    delete ui;
}

// функція для введення назви файлу, у який користувач хоче записати результат
void saveFile::on_pushButton_clicked()
{
    file_name = ui->line->text().toStdString();
    if (file_name == ""){
        QApplication::beep();
        return;
    }
    std::ofstream out(file_name);
    if(out){
        out << expression << " = " << result << '\n' << "Нижня межа: " <<
                a << "\nВерхня межа: "<< b <<
               "\nКількість розбиттів функції: " << divides <<
               "\nМаксимальна глибина рекурсії: " << depth;
        this->close();
    } else {
        QApplication::beep();
    }
    out.close();
}

