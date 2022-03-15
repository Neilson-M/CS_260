#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "graph_class.h"

using std::cin;
using std::cout;
using std::endl;

int get_rand_length(){
    int rand_length;

    rand_length = rand() % 10 + 1;

    return rand_length;
}

void create_graph(Graph *my_graph, vector<string> starter_names){
    for(auto i:starter_names){
        my_graph->add_graph_node(i);
    }
    // Aaron -> Brad
    my_graph->add_graph_edge(get_rand_length(), my_graph->pull_graph_node_list().at(0), my_graph->pull_graph_node_list().at(1));
    // Aaron -> Charlie
    my_graph->add_graph_edge(get_rand_length(), my_graph->pull_graph_node_list().at(0), my_graph->pull_graph_node_list().at(2));
    // Brad -> Charlie
    my_graph->add_graph_edge(get_rand_length(), my_graph->pull_graph_node_list().at(1), my_graph->pull_graph_node_list().at(2));
    // Charlie -> David
    my_graph->add_graph_edge(get_rand_length(), my_graph->pull_graph_node_list().at(2), my_graph->pull_graph_node_list().at(3));
    // Charlie -> Erin
    my_graph->add_graph_edge(get_rand_length(), my_graph->pull_graph_node_list().at(2), my_graph->pull_graph_node_list().at(4));
    // David -> Erin
    my_graph->add_graph_edge(get_rand_length(), my_graph->pull_graph_node_list().at(3), my_graph->pull_graph_node_list().at(4));
}

void pretty_print(Graph *my_graph){
    for(auto i:my_graph->pull_graph_node_list()){
        cout << "Node name: " << *i->pull_name() << endl;
        string neighborhood = {};
        for(auto j:i->pull_neighbors()){
            neighborhood += *j->pull_name();
            neighborhood += " ";
        }
        cout << "Node neighbors: " << neighborhood << endl;
    }
    for(auto i:my_graph->pull_graph_edge_list()){
        cout << "Edge of length (" << i->pull_length() << ") from " << *i->pull_source()->pull_name() << " to " << *i->pull_end()->pull_name() << endl;
    }
}

int main(int argc, char **argv){
    srand(time(NULL));
    Graph *my_graph = new Graph();
    string name_list[5] = {"Aaron", "Brad", "Charlie", "David", "Erin"};
    vector<string> starter_names;
    for(int i=0; i<5; i++){
        starter_names.push_back(name_list[i]);
    };
    for(auto i:starter_names){
        cout << i << endl;
    }
    create_graph(my_graph, starter_names);
    pretty_print(my_graph);


    // if(my_graph.pull_graph_node_list().size() >= 2){

    // }


    // if(graph_node_list.size() >= 2){
    //            add_graph_edge(edge_length, edge_source, edge_end);
    //         }
    //         else{
    //             cout << "You only have " << graph_node_list.size() << " node(s) in the graph. You must add " << (2-graph_node_list.size()) << " more node(s) in order to create an edge." << endl;
    //         }
    // my_graph.add_graph_node("Michael");
    return 0;
}

/*

*/


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

/*
1. Create some tests before you start coding
2. Implement a graph class with at least:
	1. a function to add a new vertex to the graph (perhaps add_vertex(vertex_name))
	2. a function to add a new edge between two vertices of the graph (perhaps add_edge(source, destination) or source.add_edge(destination))
	3. a function for a shortest path algorithm (perhaps shortest_path(source, destination))
	4. a function for a minimum spanning tree algorithm (example min_span_tree())
3. Analyze the complexity of all of your graph behaviors
*/
