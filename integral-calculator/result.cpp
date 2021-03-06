#include "result.h"
#include "ui_result.h"

Result::Result(QWidget *parent, std::string str, double lower, double upper, int index) :
    QDialog(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
        expression = new Expression(str);
        a = lower;
        b = upper;
        defined = true;
        calls = 1; // кількість виклику функції для обрахунку інтеграла (к-ість розбиття функції)
        depth = 1;
        tree = new Tree(expression->getPost_fix());
        s = NULL;

        QPixmap q("/Users/yakiv/Desktop/integral-calculator/integral-calculator/images/integral-white.png");
        ui->label_2->setPixmap(q);

//        check_bounds(); // перевірка меж функції

        if (defined){
            if (index == 0){
                result = Riemann(tree, a, b, 1e-7, defined, 1, depth, calls);
            } else if (index == 1){
                result = Trapezoidal(tree, a, b, 1e-7, defined, 1, depth, calls);
            } else {
                result = Simpson(tree, a, b, 1e-9, defined, 1, depth, calls);
            }

            if (defined) {

                make_graph(); //побудова графіка

//                ui->integral->setText("f(x)dx = " + QString::number(result));
                ui->integral->setText("f(x)dx = " + QString::number(result, 10, 8));
                ui->lower->setText(QString::number(a));
                ui->upper->setText(QString::number(b));

                ui->depth->setText(" Глибина рекурсії: " + QString::number(depth));
                ui->divided->setText(" Кількість розбиття підінтегральної функціії: \n " + QString::number(calls));

                if (depth == 22 && calls > 8000000){
                    ui->depth->setStyleSheet("QLabel { border-radius: 6px;"
                                                      "background-color: rgb(0,0,0);"
                                                      "border-style:inset;"
                                                      "color: red; }");
                }

            } else {
                undefined(); // якщо інтеграл невизначений
            }
        } else {
            undefined(); // теж саме
        }
}

Result::~Result()
{
    delete ui;
    delete expression;
    delete tree;

    if (s){
        delete s;
    }
}

//функція, в якій обраховується 100 точок графіка, для побудови графіка
void Result::make_graph(){
    int size = (b - a) * 100;
      QVector <double> x(size), y(size);
      double step = (b - a) / size;
      double curr = a;
      double min = DBL_MAX, max = -DBL_MAX;
      for (int i = 0; i < size; i++)
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
      ui->graphic->xAxis->setRange(a - (b - a) * 0.1, b + (b - a) * 0.1);
      ui->graphic->yAxis->setRange(min - (max - min) * 0.1, max + (max - min) * 0.1);
      ui->graphic->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}

//функція, для відкриття вікна із введеням назви файли, у який користувач хоче записати результат
void Result::on_pushButton_clicked()
{
    s = new saveFile(this, std::to_string(result), expression->getExpression(), calls, depth, a, b);
    s->setWindowTitle("Save in file");
    s->setModal(true);
    s->show();
}

//якщо інтеграл невизначений на краях, то він навіть не почне обраховуватись
void Result::check_bounds(){
    try {
        tree->evaluate(a);
        tree->evaluate(b);
    }  catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        defined = false;
    }
}

//якщо інтеграл невизначений
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
    undefined->setGeometry(QRect(165, 120, 300, 100));
    undefined->setStyleSheet("QLabel { border-radius: 8px;"
                                      "border-color: rgb(88, 92, 94);"
                                      "border-width: 2px;"
                                      "border-style:inset;"
                                      "color: white; }");

    undefined->setAlignment(Qt::AlignCenter);
    undefined->setText("На даному проміжку інтеграл невизначений");
}

