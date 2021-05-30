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
    std::string expression;
    std::vector <std::string> in_fix;
    std::vector <std::string> post_fix;
};

#endif // EXPRESSION_H
