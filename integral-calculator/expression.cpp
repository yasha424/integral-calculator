#include "expression.h"

Expression::Expression(std::string exp) {
    expression = exp;

    in_fix = make_in_fix(expression);

    post_fix = make_post_fix(in_fix);
}



std::string Expression::getExpression(){
    return expression;
}

std::vector <std::string> Expression::getIn_fix(){
    return in_fix;
}

std::vector <std::string> Expression::getPost_fix(){
    return post_fix;
}


bool Expression::is_operator(char ch){
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '^' || ch == '(' ||
        ch == ')') {
        return true;
    }
    return false;
}

//робить з інфіксної строки інфіксний вектор строк
std::vector <std::string> Expression::make_in_fix(std::string exp){
    std::string tmp;
    int start = 0;
    std::vector <std::string> res;
    for (size_t i = 0; i < exp.size();) {
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

//послідовність операцій
int Expression::pemdas(std::string str){
    if (str == "+" || str == "-") {
        return 1;
    } else if (str == "*" || str == "/"){
        return 2;
    } else if (str == "^"){
        return 3;
    } else {
        return 0;
    }
}

//із вхідного інфіксного виразу у вигляду вектору строк, робить постофіксний вектор строк для подальших обчислень
std::vector <std::string> Expression::make_post_fix(std::vector <std::string> exp){
    std::vector <std::string> res;
    std::stack <std::string> st;
    st.push("#");

    for (size_t i = 0; i < exp.size(); i++){
        if (isalnum(exp[i][0])){
            res.push_back((exp[i]));
        } else if (exp[i] == "(") {
            st.push(exp[i]);
        } else if (exp[i] == "^"){
            st.push(exp[i]);
        } else if (exp[i] == ")"){
            while (st.top() != "#" && st.top() != "("){
                res.push_back(st.top());
                st.pop();
            }
            st.pop();
        } else {
            if (pemdas(exp[i]) > pemdas(st.top())){
                st.push(exp[i]);
            } else {
                while (st.top() != "#" && pemdas(exp[i]) <= pemdas(st.top())){
                    res.push_back(st.top());
                    st.pop();
                }
                st.push(exp[i]);
            }
        }
    }
    while (st.top() != "#"){
       res.push_back(st.top());
       st.pop();
    }
    return res;
}
