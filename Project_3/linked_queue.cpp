#include <iostream>

#include "node.cpp"

using std::cin;
using std::cout;
using std::endl;

/* create front and rear pointers
create first node, set front* = first node


*/
Node *front = nullptr;
Node *rear = nullptr;

int queue_len = 0;

void enqueue(int new_value){ // Complexity: O(1)
    Node *new_node = new Node{new_value, nullptr};
    // queue_len++;
    if (rear != nullptr) {
        rear = new_node;
        // cout << "front->value: " << front->value << endl;
        // cout << "rear->value: " << rear->value << endl;
        // cout << "The length of your queue is: " << queue_len << endl;
        if (rear->next == nullptr) {
            cout << "rear->next == nullptr" << endl;
        }
    }
    else {
        rear = new_node;
        front = rear;
        // cout << "The length of your queue is: " << queue_len << endl;
        // cout << "front->value: " << front->value << endl;
        // cout << "rear->value: " << rear->value << endl;
    }
}

int dequeue(){ // Complexity: O(1)
    if (front != nullptr){
        int pop_value = front->value;
        front = front->next;
        return pop_value;
    }
    else {
        cout << "There's nothing in the queue!" << endl;
        return -999;
    }
}

int peek_front(){ // Complexity: O(1)
    if (front != nullptr){
        cout << front->value << endl;
        int peek_value = front->value;
        return peek_value;
    }
    else{
        cout << "There's nothing in the queue!" << endl;
        return -999;
    }
}

void create_linked_list(int starter_length){ // Complexity: O(n)
    for (int i = 0; i < starter_length; i++){
        int user_value;
        cout << "Enter a positive integer (" << (i + 1) << "/" << starter_length << "): ";
        cin >> user_value;
        enqueue(user_value);
    }
}

void test_dequeue(){
    front = nullptr;
    int test_result = dequeue();
    cout << "Expected output: -999. Actual output: " << test_result << endl;

    Node *test_node = new Node{5, nullptr};
    front = test_node;
    test_result = dequeue();
    cout << "Expected output: 5. Actual output: " << test_result << endl;
    delete test_node;
}

void test_peek(){
    front = nullptr;
    int test_result = peek_front();
    cout << "Expected output: -999 Actual output: " << test_result << endl;

    Node *test_node = new Node{5, nullptr};
    front = test_node;
    test_result = peek_front();
    cout << "Expected output: 5. Actual output: " << test_result << endl;
    delete test_node;
}

void run_test(){
    // Tests for enqueue() are commented out within the function.
    test_dequeue();
    test_peek();
}

int main(int argc, char **argv){
    // run_test();
    create_linked_list(5);
    int pop_value = dequeue();
    cout << pop_value << endl;
    int peek_value = peek_front();
    cout << peek_value << endl;
};
