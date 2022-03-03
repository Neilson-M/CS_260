#include <iostream>
// #include <array>
#include <string>
#include "binary_node.cpp"

using std::string;
using std::cin;
using std::cout;
using std::endl;

Node *root = nullptr;

void add_node(int insert_value){
	Node *temp_pointer = root;
	Node *new_node = new Node{insert_value, 1, nullptr, nullptr};
	if(root == nullptr){
		root = new_node;
	}
	else{
		while(true){
			if(insert_value < temp_pointer->value){ // Traverse left down bst
				if(temp_pointer->left != nullptr){
					temp_pointer = temp_pointer->left;
				}
				else{
					temp_pointer->left = new_node;
					break;
				}
			}
			else if(insert_value > temp_pointer->value){ // Traverse right down bst
				if(temp_pointer->right != nullptr){
					temp_pointer = temp_pointer->right;
				}
				else{
					temp_pointer->right = new_node;
					break;
				}
			}
			else if(insert_value == temp_pointer->value){ // Stack on current node
				temp_pointer->stack_count++;
				break;
			}
			else{ // Bad end
				cout << "You shouldn't be here. The balrog now knows your scent. Run." << endl;
				break;
			}
		}
	}
}

int remove_node(int remove_value){
	return 0;
}

void pre_order_search(int node_value){
	
}

void post_order_search(int node_value){
	
}

void in_order_search(int node_value){
	
}

void breadth_first_search(int node_value){
	
}

void bfs_enqueue(){
	
}

void bfs_dequeue(){
	
}

void create_binary_tree(int *root_value_array){
	// for(auto i : root_value_array){
	for(int i = 0; i < 9; i++){
		add_node(root_value_array[i]);
	}
	Node *temp_pointer = root;
	string print_string;
	print_current_tree(temp_pointer, print_string);
}

void print_current_tree(Node *temp_pointer, string print_string){ // Pre-order search w/o search
	/*
	1. Access Node
	2. Recursively travel Left
	3. Recursively travel Right
	*/
	if(!print_string.empty()){
		print_string = print_string + ", " + temp_pointer->value;
	}
	else{
		print_string = temp_pointer->value;
	}
	if(temp_pointer->left != nullptr){
		
	}
}

void destroy_binary_tree(){
	
}

int main(int argc, char **argv){
	int esc_val = 1;
    int menu_select;
    int node_value;
	
	// std::array<int, 9> root_value_array = {10, 6, 5, 3, 9, 17, 13, 15, 20}; // I tried
	int root_value_array[9] = {10, 6, 5, 3, 9, 17, 13, 15, 20};
	create_binary_tree(root_value_array);
	
	while(esc_val){
		cout << "What would you like to do? [1]:Add a node. [2]:Remove a node and return its value. [3]:Exit." << endl;
		cin >> menu_select;
		
		if(menu_select == 1){
			cout << "What number would you like to add to the tree?" << endl;
			cin >> node_value;
			add_node(node_value);
		}
		else if(menu_select == 2){
			cout << "What number would you like to remove from the tree?" << endl;
			cin >> node_value;
			remove_node(node_value);
		}
		else{
			if(menu_select == 3){
				cout << "You have chosen to exit the program. Goodbye." << endl;
				esc_val--;
			}
			else{
				cout << "Sorry, that entry could not be parsed. Please try again." << endl;
			}
		}
	}
	
	
	return 0;
}

/*
I just had the successor function return the successor's parent. 
Because you can reach down so easily.
*/
