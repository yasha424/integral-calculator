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

        if (defined){
            if (index == 0){
                result = Riemann(tree, a, b, 1e-5, defined, 1, depth, calls);
            } else if (index == 1){
                result = Trapezoidal(tree, a, b, 1e-9, defined, 1, depth, calls);
            } else {
                result = Simpson(tree, a, b, 1e-11, defined, 1, depth, calls);
            }

            if (defined) {

                make_graph();

                ui->integral->setText("f(x) = " + QString::number(result));
                ui->lower->setText(QString::number(a));
                ui->upper->setText(QString::number(b));

                ui->depth->setText(" Глибина рекурсії: " + QString::number(depth));
                ui->divided->setText(" Кількість розбиття підінтегральної функціії: \n " + QString::number(calls));
            } else {
                undefined();
            }
        } else {
            undefined();
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
      double curr = a;
      double min = DBL_MAX, max = -DBL_MAX;
      for (int i = 0; i <= 100; i++)
      {
        x[i] = curr;
        y[i] = tree->evaluate(curr);
        if (min > y[i]){
            min = y[i];
        }
        if (max < y[i]){
            max = y[i];
        }
        curr += step;
      }
      ui->graphic->addGraph();
//      ui->graphic->
      ui->graphic->graph(0)->setData(x, y);
      ui->graphic->graph(0)->setPen(QPen(Qt::blue));
      ui->graphic->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
      ui->graphic->xAxis->setLabel("x");
      ui->graphic->yAxis->setLabel("y");
      ui->graphic->xAxis->setRange(a , b);
      ui->graphic->yAxis->setRange(min, max);
      ui->graphic->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}

void Result::on_pushButton_clicked()
{
    s = new saveFile(this, std::to_string(result), expression->getExpression());
    s->setWindowTitle("Save in file");
    s->setModal(true);
    s->show();
}

void Result::check_bounds(){
    try {
        tree->evaluate(a);
        tree->evaluate(b);
    }  catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        defined = false;
    }
}

void Result::undefined(){
    ui->depth->hide();
    ui->divided->hide();
    ui->graphic->hide();
    ui->integral->hide();
    ui->pushButton->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();

    QLabel *undefined = new QLabel(this);
    undefined->setGeometry(QRect(165, 120, 300, 100));  // 10,10,30,80    165, 100, 465, 100
    undefined->setStyleSheet("QLabel { border-radius: 8px;"
                                      "border-color: rgb(88, 92, 94);"
                                      "border-width: 2px;"
                                      "border-style:inset;"
                                      "color: white; }");

    undefined->setAlignment(Qt::AlignCenter);
    undefined->setText("На даному проміжку інтеграл невизначений");
}

