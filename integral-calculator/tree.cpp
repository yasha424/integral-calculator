#include "tree.h"
#define pi 3.1415926535

Tree::Tree(std::vector <std::string> str){
    std::stack <Node*> st;
    Node *top, *left, *right;

    for (size_t i = 0; i < str.size(); i++) {
        if (!is_operator(str[i][0])) {
            top = new_node(str[i]);

            st.push(top);
        } else {
            top = new_node(str[i]);

            left = st.top();
            st.pop();
            right = st.top();
            st.pop();
            top->left = left;
            top->right = right;

            st.push(top);
        }
    }
    root = st.top();
    st.pop();
}

Tree::~Tree(){
    delete root;
}

// створення нового вузла
Node* Tree::new_node(std::string str){
    Node *node = new Node;
    node->left = node->right = NULL;
    node->value = str;
    return node;
}

bool Tree::is_operator(char ch){
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '^') {
        return true;
    }
    return false;
}

void Tree::traverse(){
    traverse(root, 0);
}

void Tree::traverse(Node *node, int depth){
    if (node){
        traverse(node->left, depth + 1);

        for (int i = 0; i < depth; i++){
            std::cout << "   ";
        }
        std::cout << node->value << std::endl;

        traverse(node->right, depth + 1);
    }
}

double Tree::evaluate(double x){
    return evaluate(root, x);
}

// функція для обрахунку дерева у точці х
double Tree::evaluate(Node *node, double x){
    if (!node->left && !node->right){
        if (node->value == "x")
            return x;
        if (node->value == "pi")
            return pi;

        return stod(node->value);
    }

    double l_sub_tree = evaluate(node->left, x);

    double r_sub_tree = evaluate(node->right, x);

    if (node->value == "+"){
        return r_sub_tree + l_sub_tree;
    } else if (node->value == "-"){
        return r_sub_tree - l_sub_tree;
    } else if (node->value == "*"){
        return r_sub_tree * l_sub_tree;
    } else if (node->value == "/"){
        if (l_sub_tree != 0){
            return r_sub_tree / l_sub_tree;
        } else {
            throw std::runtime_error("Math error: Attempted to divide by Zero");
        }
    } else {
        if ((r_sub_tree < 0 && l_sub_tree != (int)l_sub_tree) || (r_sub_tree == 0 && l_sub_tree < -1) || l_sub_tree > 50 ||
             (abs(r_sub_tree) > 20 && abs(l_sub_tree) > 10) || (abs(r_sub_tree) > 10 && abs(l_sub_tree) > 25)){
            throw std::runtime_error("Math error: Negative number in square root");
        } else {
            return pow(r_sub_tree, l_sub_tree);
        }
    }
}
