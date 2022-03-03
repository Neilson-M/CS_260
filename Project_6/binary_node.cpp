#include <iostream>

using std::cout;
using std::endl;

struct Node{
    int value;
    int stack_count;
    Node *left;
    Node *right;
    
    Node(int value, int stack_count, Node *left, Node *right){
        this->value = value;
        this->stack_count = stack_count;
        this->left = left;
        this->right = right;
    }

    // Node(int value) {
    //     Node(value, 1, nullptr, nullptr);
    // }
};
