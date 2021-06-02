#ifndef EXPRESSION_H
#define EXPRESSION_H

#pragma once
#include <string>
#include <stack>
#include <vector>
#include <iostream>

class Expression
{
public:
    Expression(){}

    Expression(std::string exp);

    std::string getExpression();

    std::vector <std::string> getIn_fix();

    std::vector <std::string> getPost_fix();

    std::vector <std::string> make_in_fix(std::string);

    std::vector <std::string> make_post_fix(std::vector <std::string>);

    bool is_operator(char);

    int pemdas(std::string);

private:
    std::string expression;  // вираз у вигляді строки
    std::vector <std::string> in_fix; // вираз у інфіксному вигляді вектору строк
    std::vector <std::string> post_fix; // вираз постфіксному вигляді вектору строк
};

#endif // EXPRESSION_H
