#include <iostream>

#include "node.cpp"

using std::cout;
using std::endl;

Node header = nullptr;

void insert_node(node_value, insert_after){
    Node *temp_pointer = header;
    Node *temp_next = nullptr;
    Node *node_to_add = new Node(int node_value);
    
    for (int i = 0; i < insert_after; i++){
        *temp_pointer = *temp_pointer->next;
    }
    
    *temp_next = *temp_pointer->next;
    *temp_pointer->next = *node_to_add;
    *node_to_add->next = *temp_next;
}

int main(int argc, char **argv){
    return 0;
}
