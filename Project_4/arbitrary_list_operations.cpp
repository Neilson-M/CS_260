#include <iostream>
#include <string>

#include "node.cpp"

using std::cin;
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
//                 cout << "The index you're looking for is outside the searchable range." << endl;
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
    string print_list;
//     std::string print_list; // might need std:: b4 string dec
    Node *temp_pointer = header;
    print_list = std::to_string(temp_pointer->value);
    while (temp_pointer->next != nullptr){
        temp_pointer = temp_pointer->next;
        print_list += ", " + std::to_string(temp_pointer->value);
    }
    cout << "The list values in order are: " << print_list << endl;
}

int main(int argc, char **argv){
    int esc_val = 1;
//     create list here!
    while (esc_val){
        cout << "What would you like to do? [1]:Insert a node. [2]:Remove and return a node. [3]:Peek at a specific node in the list. [4]:Print all the values in the list. [5]:Exit." << endl;
        cin >> menu_select;
        
        switch(menu_select){
            case 1: // void insert_node(int node_value, int insert_after)
                cout << "What value would you like to add to the list?" << endl;
                cin >> node_value;
                cout << "What index would you like to insert the new node after?" << endl;
                cin >> insert_after;
                insert_node(node_value, insert_after);
            case 2: // int pop_node(int node_index)
                int pop_value;
                cout << "Which node index do you want to remove from the list?" << endl;
                cin >> node_index;
                pop_value = pop_node(node_index);
                if (pop_value == -999){
                    cout << "There was no node to remove at index " << node_index << "." << endl;
                }
                else{
                    cout << "You have removed node " << node_index << " from the list. It's value was " << pop_value << "." << endl;
                }
            case 3: // int peek(int node_index)
                int peek_value;
                cout << "Which node index do you want to look at?" << endl;
                cin >> node_index;
                peek(peek_value);
            case 4: // void read_list()
                read_list();
            default: // exit
                esc_val--;
                cout << "Now exiting." << endl;
        }
    }
    
    return 0;
}
