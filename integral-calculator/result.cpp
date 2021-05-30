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
//    make_graph();

    tree = new Tree(expression->getPost_fix());
//    tree->traverse();
//    std::cout << tree->evaluate(1) << std::endl;

    if (index == 0){
        result = Riemann(tree, a, b, 1e-7, defined);
//        std::cout << result << std::endl;
    } else if (index == 1){
        result = Trapezoidal(tree, a, b, 1e-7, defined);
    } else {

    }

    if (defined) {
        std::cout << result << std::endl;
    }

}

Result::~Result()
{
    delete ui;
}


void Result::test(){
//    expression = to_postfix(expression);
}

void Result::make_graph(){
//    QVector<double> x(251), y0(251), y1(251);
//    for (int i=0; i<251; ++i)
//    {
//      x[i] = i;
//      y0[i] = qExp(-i/150.0)*qCos(i/10.0); // exponentially decaying cosine
//      y1[i] = qExp(-i/150.0);              // exponential envelope
//    }
//    // configure right and top axis to show ticks but no labels:
//    // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
//    ui->graphic->xAxis2->setVisible(true);
//    ui->graphic->xAxis2->setTickLabels(false);
//    ui->graphic->yAxis2->setVisible(true);
//    ui->graphic->yAxis2->setTickLabels(false);
//    // make left and bottom axes always transfer their ranges to right and top axes:
//    connect(ui->graphic->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->graphic->xAxis2, SLOT(setRange(QCPRange)));
//    connect(ui->graphic->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->graphic->yAxis2, SLOT(setRange(QCPRange)));
//    // pass data points to graphs:
//    ui->graphic->graph(0)->setData(x, y0);
//    ui->graphic->graph(1)->setData(x, y1);
//    // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
//    ui->graphic->graph(0)->rescaleAxes();
//    // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
//    ui->graphic->graph(1)->rescaleAxes(true);
//    // Note: we could have also just called ui->graphic->rescaleAxes(); instead
//    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
//    ui->graphic->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}
