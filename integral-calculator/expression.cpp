#include "expression.h"

Expression::Expression(std::string exp) {
    expression = exp;

    in_fix = make_in_fix(expression);

    post_fix = make_post_fix(expression);
}



std::string Expression::getExpression(){
    return expression;
}

std::vector <std::string> Expression::make_in_fix(std::string exp){

}

std::vector <std::string> Expression::make_post_fix(std::string exp){

}
