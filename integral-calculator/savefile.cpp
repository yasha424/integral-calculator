#include "savefile.h"
#include "ui_savefile.h"

saveFile::saveFile(QWidget *parent, std::string res, std::string exp) :
    QDialog(parent),
    ui(new Ui::saveFile)
{
    ui->setupUi(this);
    expression = exp;
    result = res;
}

saveFile::~saveFile()
{
    delete ui;
}

void saveFile::on_pushButton_clicked()
{
    file_name = ui->line->text().toStdString();
    if (file_name == "")
        return;

    std::ofstream out(file_name);
    if(out){
        out << expression;
        out << " = ";
        out << result;
        this->close();
    } else {
        QApplication::beep();
    }
    out.close();
}

