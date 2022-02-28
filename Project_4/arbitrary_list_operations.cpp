#include <iostream>
#include <string>

#include "node.cpp"

using std::cout;
using std::endl;

Node *header = nullptr;

void insert_node(int node_value, int insert_after){
    Node *temp_pointer = header;
    Node *temp_next = nullptr;
    Node *node_to_add = new Node{node_value}; // MAKE SURE TO ADD DELETE!!!
    
    for (int i = 0; i < insert_after; i++){
        *temp_pointer = *temp_pointer->next;
    }
    
    *temp_next = *temp_pointer->next;
    *temp_pointer->next = *node_to_add;
    *node_to_add->next = *temp_next;
}

int pop_node(int node_index){
    Node *temp_pointer = header;
    Node *prev_pointer = nullptr;
    
    int pop_value = -999;

    if (node_index != 0){
        for (int i = 0; i < node_index; i++){
            if (temp_pointer->next != nullptr){
                *prev_pointer = *temp_pointer;
                *temp_pointer = *temp_pointer->next;
            }
            else {
                cout << "The index you're looking for is outside the searchable range." << endl;
                return pop_value; // pop_value = -999
            }
        }
        int pop_value = temp_pointer->value;
        if (temp_pointer->next != nullptr){
            *prev_pointer->next = *temp_pointer->next;
        }
        else {
            prev_pointer->next = nullptr;
        }
    }
    else {
        int pop_value = header->value;
        if (header->next != nullptr){
            *header = *header->next;
        }
        else {
            header = nullptr;
        }
    }
    
    return pop_value; // pop_value = temp_pointer->value or header->value
}

int peek(int node_index){
    Node *temp_pointer = header;
    int i = 0;
    while (i < node_index){
        temp_pointer = temp_pointer->next;
    }
    int peek_value = temp_pointer->value;
    return peek_value;
}

void read_list(){
    /*
    make string
    step thru list and concatinate into string
    print string
    */
}

int main(int argc, char **argv){
    return 0;
}
