#include "evaluation.h"

//алгоритм для обчислення інтегралу методом прямокутників
double Riemann(Tree *tree, double a, double b, double eps, bool &defined, size_t stat, size_t &level, size_t &calls){
    if (defined){
        double left, right, mid;
        try {
            left = tree->evaluate(a + (b - a) / 4) * (b - a) / 2;
            right = tree->evaluate(a + (b - a) / 4 * 3) * (b - a) / 2;
            mid = tree->evaluate((a + b) / 2) * (b - a);

        } catch (std::runtime_error& e) {
            defined = false;
        }
        if (stat > 22){
            return left + right;
        }
        if (abs(left + right - mid) <= eps){
            if (level < stat){
                level = stat;
            }
            return left + right;
        }
        calls += 2;
        return Riemann(tree, a, (b + a) / 2, eps/2, defined, stat+1, level, calls) + Riemann(tree, (b + a) / 2, b, eps/2, defined, stat+1, level, calls);
    }
    return 0;
}

//алгоритм для обчислення інтегралу методом трапецій
double Trapezoidal(Tree *tree, double a, double b, double eps, bool &defined, size_t stat, size_t &level, size_t &calls){
    if (defined){
        double left, right, mid;

        try {
            left = (tree->evaluate(a) + tree->evaluate((a + b) / 2)) / 2 * (b - a) / 2;
            right = (tree->evaluate(b) + tree->evaluate((a + b) / 2)) / 2 * (b - a) / 2;
            mid = (tree->evaluate(a) + tree->evaluate(b)) / 2 * (b - a);
        }  catch (std::runtime_error& e) {
            defined = false;
        }
        if (stat > 22){
            return left + right;
        }
        if (abs(left + right - mid) <= eps){
            if (level < stat){
                level = stat;
            }
            return left + right;
        }
        calls += 2;
        return Trapezoidal(tree, a, (b + a) / 2, eps/2, defined, stat+1, level, calls) + Trapezoidal(tree, (b + a) / 2, b, eps/2, defined, stat+1, level, calls);
    }
    return 0;
}

//алгоритм для обчислення інтегралу методом Сімпсона
double Simpson(Tree *tree, double a, double b, double eps, bool &defined, size_t stat, size_t &level, size_t &calls){
    if (defined){
        double left, right, mid;

        try {
            left = sub_simpson(tree, a, a + (b - a) / 2);
            right = sub_simpson(tree, a + (b - a) / 2, b);
            mid = sub_simpson(tree, a, b);
        }  catch (std::runtime_error& e) {
            defined = false;
        }
        if (stat > 22){
            return left + right;
        }
        if (abs(left + right - mid) <= eps){
            if (level < stat){
                level = stat;
            }
            return left + right;
        }
        calls += 2;
        return Simpson(tree, a, (b + a) / 2, eps/2, defined, stat+1, level, calls) + Simpson(tree, (b + a) / 2, b, eps/2, defined, stat+1, level, calls);
    }
    return 0;
}

//власне сама формула Сімпсона
double sub_simpson(Tree *tree, double a, double b){
    return ((tree->evaluate(a) + 4 * tree->evaluate(a + (b - a) / 2) + tree->evaluate(b)) * (b - a) / 6);
}
