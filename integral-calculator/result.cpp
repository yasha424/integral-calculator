#include "result.h"
#include "ui_result.h"

Result::Result(QWidget *parent, std::string str, double lower, double upper, int index, bool ex) :
    QDialog(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
        expression = new Expression(str);
        a = lower;
        b = upper;
        defined = true;
        calls = 1;
        depth = 1;
        tree = new Tree(expression->getPost_fix());

        QPixmap q("/Users/yakiv/Desktop/integral-calculator/integral-calculator/images/integral-white.png");
        ui->label_2->setPixmap(q);

        if (index == 0){
            result = Riemann(tree, a, b, 1e-5, defined, 1, depth, calls);
        } else if (index == 1){
            result = Trapezoidal(tree, a, b, 1e-9, defined, 1, depth, calls);
        } else {
            result = Simpson(tree, a, b, 1e-11, defined, 1, depth, calls);
        }

        if (defined) {
//            ui->label->setText(QString::number(result) + ",  " + QString::number(depth) + ",  " + QString::number(calls));


            make_graph();

            ui->integral->setText("f(x) = " + QString::number(result));
            ui->lower->setText(QString::number(a));
            ui->upper->setText(QString::number(b));

            ui->depth->setText(" Глибина рекурсії: " + QString::number(depth));
            ui->divided->setText(" Кількість розбиття підінтегральної функціії: \n " + QString::number(calls));


        }
}

Result::~Result()
{
    delete ui;
}


void Result::test(){
}

void Result::make_graph(){
      QVector<double> x(101), y(101);
      double step = (b - a) / 100;
      double min = DBL_MAX, max = -DBL_MAX;
      int ind = 0;
      for (double i = a; i < b && ind <= 100; i += step)
      {
        x[ind] = i;
        y[ind] = tree->evaluate(i);
        if (min > y[ind]){
            min = y[ind];
        }
        if (max < y[ind]){
            max = y[ind];
        }
        ind++;
      }
      ui->graphic->addGraph();
      ui->graphic->graph(0)->setData(x, y);
      ui->graphic->graph(0)->setPen(QPen(Qt::blue));
      ui->graphic->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
      ui->graphic->xAxis->setLabel("x");
      ui->graphic->yAxis->setLabel("y");
      ui->graphic->xAxis->setRange(a - 1, b + 1);
      ui->graphic->yAxis->setRange(min - 1, max + 1);
      ui->graphic->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}

void Result::on_pushButton_clicked()
{
    // to do
}

