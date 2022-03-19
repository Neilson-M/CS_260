#include <iostream>

#include "graph_edge_class.h"

using std::cin;
using std::cout;
using std::endl;

class Graph{
    private:
        vector<Graph_node *> graph_node_list;
        vector<Graph_edge *> graph_edge_list;

    public:
        // add, remove functions go here!!!
        void add_graph_node(string node_name){ // O(1)
            vector<Graph_node *> neighbors;
            Graph_node *new_graph_node = new Graph_node(node_name, neighbors, 9999, nullptr, false);
            graph_node_list.push_back(new_graph_node);
        }
        void add_graph_edge(int edge_length, Graph_node *edge_source, Graph_node *edge_end){ // O(1)
            Graph_edge *new_graph_edge = new Graph_edge(edge_length, edge_source, edge_end);
            graph_edge_list.push_back(new_graph_edge);
            edge_source->set_neighbor(edge_end);
            edge_end->set_neighbor(edge_source);
            // edge_source->pull_neighbors().push_back(edge_end);
            // edge_end->pull_neighbors().push_back(edge_source);
        }
        vector<Graph_node *> pull_graph_node_list(){ // O(1)
            return graph_node_list;
        }
        vector<Graph_edge *> pull_graph_edge_list(){ // O(1)
            return graph_edge_list;
        }
};
