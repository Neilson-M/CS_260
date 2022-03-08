#include <string>
#include <vector>

#include "Graph_node.hpp"

using std::vector;

class Graph{
    private:
        vector<Graph_node *> nodes;

    public:
        // default constructor should be fine
        Graph_node *add_node(string new_name);
        Graph_node *add_node(Graph_node *new_node);
        string to_string();
};
