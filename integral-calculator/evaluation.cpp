#include "evaluation.h"

double Riemann(Tree *tree, double a, double b, double eps, bool &defined){
//    Integral *integral = new Integral;
    if (defined){
        double left, right, mid;
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

double Trapezoidal(Tree *tree, double a, double b, double eps, bool &defined){
    if (defined){
        double left, right, mid;

        try {
            left = tree->evaluate(a + (b - a) / 4) * (b - a) / 2;
            right = tree->evaluate(a + ((b - a) / 4) * 3) * (b - a) / 2;
            mid = tree->evaluate(a + (b - a) / 2) * (b - a);
        }  catch (std::runtime_error& e) {
            std:: cout << e.what() << std::endl;
            defined = false;
        }
        if (abs(left + right - mid) <= eps){
            return left + right;
        }
        return Trapezoidal(tree, a, (b + a) / 2, eps/2, defined) + Trapezoidal(tree, (b + a) / 2, b, eps/2, defined);
    }
    return 0;
}

