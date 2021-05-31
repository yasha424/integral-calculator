#include "result.h"
#include "ui_result.h"

Result::Result(QWidget *parent, std::string str, double lower, double upper, int index, bool ex) :
    QDialog(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
//    if (ex){
        expression = new Expression(str);
        a = lower;
        b = upper;
        defined = true;
        calls = 1;
        depth = 1;
        tree = new Tree(expression->getPost_fix());

        if (index == 0){
            result = Riemann(tree, a, b, 1e-5, defined, 1, depth, calls);
        } else if (index == 1){
            result = Trapezoidal(tree, a, b, 1e-11, defined, 1, depth, calls);
        } else {
            result = Simpson(tree, a, b, 1e-14, defined, 1, depth, calls);
        }

        if (defined) {
            ui->label->setText(QString::number(result) + ",  " + QString::number(depth) + ",  " + QString::number(calls));
        }

        make_graph();
//    } else { // если файл или то что в нем не правильное

//    }

}

Result::~Result()
{
    delete ui;
}


void Result::test(){
}

void Result::make_graph(){
//    demoName = "Quadratic Demo";
      // generate some data:
      QVector<double> x(101), y(101); // initialize with entries 0..100
      double step = (b - a) / 100;
      double min = DBL_MAX, max = -DBL_MAX;
      int ind = 0;
      for (double i = a; i < b && ind <= 100; i += step)
      {
        x[ind] = i; // x goes from -1 to 1
        y[ind] = tree->evaluate(i);  // let's plot a quadratic function
//        std::cout << y[ind] << std::endl;
        if (min > y[ind]){
            min = y[ind];
        }
        if (max < y[ind]){
            max = y[ind];
        }
        ind++;
      }
      // create graph and assign data to it:
      ui->graphic->addGraph();
      ui->graphic->graph(0)->setData(x, y);
      ui->graphic->graph(0)->setPen(QPen(Qt::blue));
      ui->graphic->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));

//      ui->graphic->xAxis->setVisible(true);

      // give the axes some labels:
      ui->graphic->xAxis->setLabel("x");
      ui->graphic->yAxis->setLabel("y");
      // set axes ranges, so we see all data:
      std::cout << min << ", " << max << std::endl;
      ui->graphic->xAxis->setRange(a - 1, b + 1);
      ui->graphic->yAxis->setRange(min - 1, max + 1);
//      ui->graphic->replot();

      ui->graphic->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}
