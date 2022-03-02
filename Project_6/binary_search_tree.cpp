#include <iostream>
#include <array>
#include "binary_node.cpp"

using std::cin;
using std::cout;
using std::endl;

Node *root = nullptr;

void add_node(int insert_value){
	Node *temp_pointer = root;
	Node *new_node = new Node(insert_value, 1, nullptr, nullptr);
	if(root == nullptr){
		root = new_node;
	}
	else{
		while(True){
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
	pass
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
	pass
}

void bfs_dequeue(){
	pass
}

/*
void create_binary_tree(int *root_value_array){
	int place_holder = 0;
	for(auto i : root_value_array){
		if(place_holder == 0){
			root = new Node{i, 1, }
		}
	}
}
*/

int main(int argc, char **argv){
	int esc_val = 1;
	// std::array<int, 9> root_value_array = {10, 6, 5, 3, 9, 17, 13, 15, 20};
	
	// create_binary_tree(root_value_array)
	
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
