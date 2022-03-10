#include <iostream>

#include "graph_node.hpp"
#include "graph.h"

using std::cout;
using std::endl;

int main(int argc, char **argv){
    Graph_node node1{"node1", vector<Graph_node *>()};
    Graph_node node2{"node2", vector<Graph_node *>()};
    Graph_node node3{"node3", vector<Graph_node *>()};

    node1.neighbors.push_back(&node2);
    node1.neighbors.push_back(&node3);
    node2.neighbors.push_back(&node3);

    // cout << "node1.name: " << node1.name << endl;
    // cout << "node2.name (directly): " << node2.name << endl;
    // cout << "node2.name (indirectly through node1): " << node1.neighbors.at(0)->name << endl;
    // cout << "node2.name (indirectly through node1): " << node1.neighbors[0]->name << endl; // also works!!

    // indexing seg faults if you go out of bounds!!!!!
    // .at throws 'out of range' error if out of bounds

    Graph my_graph;

    my_graph.add_node(&node1);
    my_graph.add_node(&node2);
    my_graph.add_node(&node3);

    Graph_node *new_node = my_graph.add_node("hello");
    node3.add_edge(new_node);
    new_node->add_edge(&node1);

    cout << "my_graph.to_string: " << my_graph.to_string() << endl;

    cout << "thanks for playing!" << endl;
    return 0;
}

/*
use dijkstra's algorithm to determine shortest path
function Dijkstra(Graph, source):
    for each vertex v in Graph.Vertices:
        dist[v] ← INFINITY
        prev[v] ← UNDEFINED
        add v to Q
    dist[source] ← 0

    while Q is not empty:
        u ← vertex in Q with min dist[u]

        for each neighbor v of u still in Q:
            alt ← dist[u] + Graph.Edges(u, v)
            if alt < dist[v]:
                dist[v] ← alt
                prev[v] ← u
    return dist[], prev[]
*/

// use: g++ -o main.exe .\graph_driver.cpp graph.cpp
// then use: ./main.exe
