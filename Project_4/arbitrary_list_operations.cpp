#include <iostream>

#include "node.cpp"

using std::cout;
using std::endl;

Node *header = nullptr;

void insert_node(node_value, insert_after){
    Node *temp_pointer = *header;
    Node *temp_next = nullptr;
    Node *node_to_add = new Node(int node_value); // MAKE SURE TO ADD DELETE!!!
    
    for (int i = 0; i < insert_after; i++){
        *temp_pointer = *temp_pointer->next;
    }
    
    *temp_next = *temp_pointer->next;
    *temp_pointer->next = *node_to_add;
    *node_to_add->next = *temp_next;
}

int pop_node(node_index){
    Node *temp_pointer = *header;
    Node *prev_pointer = nullptr;
    
    if (node_index != 0){
        for (int i = 0; i < node_index; i++){
            if (*temp_pointer->next != nullptr){
                *prev_pointer = *temp_pointer;
                *temp_pointer = *temp_pointer->next;
            }
            else {
                cout << "The index you're looking for is outside the searchable range." << endl;
                return -200;
            }
        }
        int pop_value = *temp_pointer->value;
        if (*temp_pointer->next != nullptr){
            *prev_pointer->next = *temp_pointer->next;
        }
        else {
            *prev_pointer->next = nullptr;
        }
    }
    else {
        int pop_value = *header->value;
        if (*header->next != nullptr){
            *header = *header->next;
        }
        else {
            *header = nullptr;
        }
    }
    
    return pop_value;
}

int peek(node_index){
    return peek_value;
}

int main(int argc, char **argv){
    return 0;
}
