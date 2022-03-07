#include <iostream>
// #include <array>
#include <string>
#include "binary_node.cpp"

using std::string;
using std::cin;
using std::cout;
using std::endl;

Node *root = nullptr;
Node *parent_node = nullptr;

void add_node(int insert_value){
	Node *temp_add_pointer = root;
	Node *new_node = new Node{insert_value, 1, nullptr, nullptr};
	if(root == nullptr){
		root = new_node;
	}
	else{
		while(true){
			if(insert_value < temp_add_pointer->value){ // Traverse left down bst
				if(temp_add_pointer->left != nullptr){
					temp_add_pointer = temp_add_pointer->left;
				}
				else{
					temp_add_pointer->left = new_node;
					break;
				}
			}
			else if(insert_value > temp_add_pointer->value){ // Traverse right down bst
				if(temp_add_pointer->right != nullptr){
					temp_add_pointer = temp_add_pointer->right;
				}
				else{
					temp_add_pointer->right = new_node;
					break;
				}
			}
			else if(insert_value == temp_add_pointer->value){ // Stack on current node
				temp_add_pointer->stack_count++;
				break;
			}
			else{ // Bad end
				cout << "You shouldn't be here. The balrog now knows your scent. Run." << endl;
				break;
			}
		}
	}
}

void remove_node(int remove_value){
	Node *temp_remove_pointer = root;
	parent_node = nullptr;
	temp_remove_pointer = pre_order_search(temp_remove_pointer, parent_node, remove_value);
	if(temp_remove_pointer != nullptr){
		/*
		1. check for temp_remove_pointer children: if none/if left xor right/else both
		2. if children, traverse branch(es), compile node values into list, find median
		3. reassign pointers for parent_node and successor_node
		*/
		if(temp_remove_pointer->left == nullptr and temp_remove_pointer->right == nullptr){ // no children
			if(temp_remove_pointer->value < parent_node->value){ // delete left child
				parent_node->left = nullptr;
				delete temp_remove_pointer;
			}
			else{ // temp_remove_pointer->value > parent_node->value // delete right child
				parent_node->right = nullptr;
				delete temp_remove_pointer;
			}
		}
		else if(temp_remove_pointer->left != nullptr xor temp_remove_pointer->right != nullptr){ // only either left or right child exixts
			if(parent_node->left != nullptr){
				
			}
			else{ // parent_node->right != nullptr
				
			}
		}
		else{ // both children exist
			pass
		}
	}
	else{
		cout << "The value you specified was not in the binary tree." << endl;
	}
}

void locate_successor(Node *parent_node){
	
}

// meant to return a node pointer
Node pre_order_search(Node *temp_pointer, Node *parent_node, int search_value){ // temp_pointer needs to = root as this gets called! set parent_node = nullptr as this gets called
	/*
	1. Access Node
	2. Recursively travel Left
	3. Recursively travel Right
	*/
	/*
	if(temp_pointer->value == search_value){
		return temp_pointer; // unsure if this will stay if temp_pointer is only defined locally as opposed to globally. does hitting [return] only once in a recursive function work?
	}
	else{
		parent_node = temp_pointer;
		if(search_value < temp_pointer->value){
			temp_pointer = temp_pointer->left;
		}
		else{
			temp_pointer = temp_pointer->right;
		}
		pre_order_search(temp_pointer, parent_node, search_value);
	}
	*/
	if(temp_pointer != nullptr){ // check if binary tree exists (temp_pointer=root so if root =nullptr, binary tree doesn't exist) // nested if statements aren't the most efficient method but I can't figure out a better way
		if(temp_pointer->value != search_value){ // Access Node, compare node value against search_value
			if(temp_pointer->left != nullptr or temp_pointer->right != nullptr){ // does temp_pointer have a ->left or ->right, are we at the bottom of the tree?
				parent_node = temp_pointer;
				if(search_value < temp_pointer->value){ // set-up to Recursively travel Left
					temp_pointer = temp_pointer->left;
				}
				else{ // set-up to Recursively travel Right
					temp_pointer = temp_pointer->right;
				}
				temp_pointer = pre_order_search(temp_pointer, parent_node, search_value); // Recursively travel Left or Right
			}
		}
		// else if(){}
	}
	else{ // if binary tree doesn't exist, say so, temp_pointer (already == nullptr) returns nullptr
		cout << "There is currently no binary tree to search through." << endl;
	}
	return temp_pointer; // how to return parent_node? maybe add parent_node value into Node struct? easier to find parent_node but maybe harder to reassign new parent_node value?
}
// return node pointer
void post_order_search(Node *temp_pointer, Node *parent_node, int search_value){ // temp_pointer needs to = root as this gets called!
	/*
	1. Recursively travel Left
	2. Recursively travel Right
	3. Access Node
	*/
	parent_node = temp_pointer;
	if(search_value < temp_pointer->value){
		temp_pointer = temp_pointer->left;
		post_order_search(temp_pointer, parent_node, search_value);
	}
	else if(search_value > temp_pointer){
		temp_pointer = temp_pointer->right;
		post_order_search(temp_pointer, parent_node, search_value);
	}
	if(search_value == temp_pointer->value){
		return temp_pointer;
	}
}
// return node pointer
void in_order_search(Node *temp_pointer, int search_value){ // temp_pointer needs to = root as this gets called!
	/*
	1. Recursively travel Left
	2. Access Node
	3. Recursively travel Right
	*/
	
}

void breadth_first_search(int search_value){
	
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
	Node *temp_create_pointer = root;
	string print_string;
	print_string = print_current_tree(temp_create_pointer, print_string);
	cout << "The full binary tree, in pre-order readout, is: " << print_string << endl;
}

// maybe needs std::string instead
string print_current_tree(Node *temp_print_pointer, string print_string){ // Pre-order travel w/o search
	/*
	1. Access Node
	2. Recursively travel Left
	3. Recursively travel Right
	*/
	if(!print_string.empty()){
		print_string = print_string + ", " + temp_print_pointer->value;
	}
	else{
		print_string = temp_print_pointer->value;
	}
	if(temp_print_pointer->left != nullptr){
		temp_print_pointer = temp_print_pointer->left;
		print_current_tree(temp_print_pointer, print_string);
	}
	if(temp_print_pointer->right != nullptr){
		temp_print_pointer = temp_print_pointer->right;
		print_current_tree(temp_print_pointer, print_string);
	}
	return print_string;
}

void destroy_binary_tree(){
	
}

int main(int argc, char **argv){
	int esc_val = 1;
    int menu_select;
    int search_value;
	
	// std::array<int, 9> root_value_array = {10, 6, 5, 3, 9, 17, 13, 15, 20}; // I tried
	int root_value_array[9] = {10, 6, 5, 3, 9, 17, 13, 15, 20};
	create_binary_tree(root_value_array);
	
	while(esc_val){
		cout << "What would you like to do? [1]:Add a node. [2]:Remove a node and return its value. [3]:Exit." << endl;
		cin >> menu_select;
		
		if(menu_select == 1){
			cout << "List an integer greater than zero that you would you like to add to the tree." << endl;
			cin >> search_value;
			add_node(search_value);
		}
		else if(menu_select == 2){
			cout << "What number would you like to remove from the tree?" << endl;
			cin >> search_value;
			remove_node(search_value);
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
