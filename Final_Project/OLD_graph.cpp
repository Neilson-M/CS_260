#include <string>

#include "graph.h"

using std::string;

Graph_node *Graph::add_node(string new_name){
    Graph_node *new_node = new Graph_node{new_name, vector<Graph_node *>()};

    this->nodes.push_back(new_node);

    return new_node;
}

Graph_node * Graph::add_node(Graph_node *new_node){
    this->nodes.push_back(new_node);

    return new_node;
}

string Graph::to_string(){
    string result = ""; // should use a string builder
    for(int i = 0; i < this->nodes.size(); i++){ // should use iterator instead, since a vector supports iterators
        result += this->nodes.at(i)->to_string() + ", ";
    }
    return result;
}
