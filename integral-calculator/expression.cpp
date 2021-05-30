#include "expression.h"

Expression::Expression(std::string exp) {
    expression = exp;

    in_fix = make_in_fix(expression);

//    post_fix = make_post_fix(expression);

}



std::string Expression::getExpression(){
    return expression;
}

std::vector <std::string> Expression::getIn_fix(){
    return in_fix;
}


bool Expression::is_operator(char ch){
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '^' || ch == '(' ||
        ch == ')') {
        return true;
    }
    return false;
}

std::vector <std::string> Expression::make_in_fix(std::string exp){
    std::string tmp;
    int start = 0;
    std::vector <std::string> res;
    for (int i = 0; i < exp.size();) {
        if (is_operator(exp[i])) {
            tmp = exp.substr(i++, 1);
            res.push_back(tmp);
            start = i;
        } else {
            while (!is_operator(exp[i]) && i < exp.size()) {
                i++;
            }
            tmp = exp.substr(start, i - start);
            res.push_back(tmp);
            start = i;
        }
    }
    return res;
}

std::vector <std::string> Expression::make_post_fix(std::string exp){

}
