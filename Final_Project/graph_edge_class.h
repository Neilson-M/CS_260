#include "graph_node_class.h"

class Graph_edge{
    private:
        int length;
        Graph_node *source; // source and end indicate the 2 neighbor nodes connected by the edge
        Graph_node *end;

    public:
        Graph_edge(int length, Graph_node *source, Graph_node *end){
            this->length = length;
            this->source = source;
            this->end = end;
        }
        int pull_length(){
            return length;
        }
        Graph_node* pull_source(){
            return source;
        }
        Graph_node* pull_end(){
            return end;
        }
};