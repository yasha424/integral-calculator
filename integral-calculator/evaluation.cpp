#include "evaluation.h"

double Riemann(Tree *tree, double a, double b, double eps, bool &defined){
//    Integral *integral = new Integral;
    if (defined){
        double left;
        double right;
        double mid;
        try {
            left = tree->evaluate(a) * (b - a) / 2;
            right = tree->evaluate((a + b) / 2) * (b - a) / 2;
            mid = tree->evaluate((double)(a + b) / 2) * (b-a);
        } catch (std::runtime_error& e) {
            std:: cout << e.what() << std::endl;
            defined = false;
        }
    //    std::cout << left << ", " << right << ", " << mid << ", " << eps << std::endl;
        if (abs(left + right - mid) <= eps){
            return left + right;
        }
        return Riemann(tree, a, (b + a) / 2, eps/2, defined) + Riemann(tree, (b + a) / 2, b, eps/2, defined);
    }
    return 0;
}


//Integral* Riemann(Tree* tree, double a, double b, double eps){
//    Integral *integral = new Integral;

//    integral = Riemann_eval(Tree* tree, double a, double b, double eps);
//}
