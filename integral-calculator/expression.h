#ifndef EXPRESSION_H
#define EXPRESSION_H

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

    std::vector <std::string> make_post_fix(std::string);

    bool is_operator(char);

//private:
    std::string expression;
    std::vector <std::string> in_fix;
    std::vector <std::string> post_fix;
};

#endif // EXPRESSION_H
