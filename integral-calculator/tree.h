#ifndef TREE_H
#define TREE_H

#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cmath>

struct Node{
    std::string value;
    Node *left, *right;
};

class Tree
{
public:
    Tree(){}

    Tree(std::vector <std::string>);

    bool is_operator(char);

    Node *new_node(std::string);

    void traverse();

    double evaluate(double);

private:
    Node *root;

    void traverse(Node* node, int depth);

    double evaluate(Node*, double);
};

#endif // TREE_H
