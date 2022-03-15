#pragma once // does some magic??? only gets done once?

#include <string>
#include <vector>

using std::string;
using std::vector;

struct Graph_node{
    string name;
    vector<Graph_node *> neighbors; // vector called neighbors, like a smart array, holds all the edges
    void add_edge(Graph_node *destination){
        // should we check for uniqueness of neighbors?
        this->neighbors.push_back(destination);
    }
    string to_string(){
        string result = "";
        result += this->name + " (neighbors: ";
        for(auto neighbor: this->neighbors){
            result += neighbor->name + ", ";
        }
        result += ")";

        return result;
    }
};
