#include "result.h"
#include "ui_result.h"

Result::Result(QWidget *parent, std::string str, double lower, double upper) :
    QDialog(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
    expression = str;
    a = lower;
    b = upper;


}

Result::~Result()
{
    delete ui;
}


void Result::test(){

}

void Result::make_graph(){

}
