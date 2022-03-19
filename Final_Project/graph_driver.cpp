#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <set>
#include <utility>

#include "graph_class.h"

using std::cin;
using std::cout;
using std::endl;

int get_rand_length(){ // O(1)
    int rand_length;

    rand_length = rand() % 10 + 1;

    return rand_length;
}

void add_node(Graph *my_graph, string node_name){ // O(1)
    my_graph->add_graph_node(node_name);
}

void add_edge(Graph *my_graph, int edge_length, int edge_source_index, int edge_end_index){ // O(1)
    my_graph->add_graph_edge(edge_length, my_graph->pull_graph_node_list().at(edge_source_index), my_graph->pull_graph_node_list().at(edge_end_index));
}

// Hi Joe, put a lot of effort into getting this working but it seems that I was unsuccessful in properly completing it. I'm not entirely sure where it fails but I'm able to at least reach the end of the algorithm, which is better than nothing.
void run_dijkstras(Graph *my_graph, Graph_node *source_node){ // O(n^4) yikes
    vector<Graph_node *> dijkstra_q;
    vector<Graph_node *> temp_vector;
    Graph_node *prev_node;
    Graph_node *node_u;
    Graph_node *node_v;
    Graph_node *last_node;
    int edge_dist;
    int alt_dist;
    int esc_val;
    for(auto i:my_graph->pull_graph_node_list()){ // for each vertex in v in Graph.Vertices
        i->update_distance(9999); // poor man's infinity // dist[v] = INFINITY
        i->update_previous(nullptr); // prev[v] = UNDEFINED
        i->update_visited(false); 
        if(*i->pull_name() != *source_node->pull_name()){ // exclude the source node from the compilation
            dijkstra_q.push_back(i);
        }
    }
    // for(auto i:dijkstra_q){
    //     cout << *i->pull_name();
    // }
    // cout << endl;
    std::reverse(dijkstra_q.begin(), dijkstra_q.end()); // reversing the vector moves the first object in from the front to the back, changing the vector from a stack format (FILO) to a queue format (FIFO)

    // for(auto i:dijkstra_q){
    //     cout << *i->pull_name();
    // }
    // cout << endl;
    source_node->update_distance(0); // dist[source] = 0
    source_node->update_visited(true);
    prev_node = source_node;
    esc_val = 0;
    while(dijkstra_q.size() > 0){ // while Q is not empty
        edge_dist = 9999;
        esc_val++;
        if(esc_val > dijkstra_q.size()){
            break;
        }
        for(auto i:my_graph->pull_graph_edge_list()){
            if(*i->pull_source()->pull_name() == *prev_node->pull_name()){
                if(i->pull_length() < edge_dist){
                    // node_u = i->pull_source(); // u <- vertex in Q w/ min dist[u]
                    node_u = i->pull_end();
                    edge_dist = i->pull_length();
                    node_u->update_distance(edge_dist);
                }
            }
        }
        node_u->update_visited(true);
        prev_node = node_u;
        // we have node_u, need to remove node_u from dijkstra_q
        // for(i:dijkstra_q) -> compare names
        for(int i=0; i<dijkstra_q.size(); i++){
            if(dijkstra_q.at(i)->pull_visited()){
                if(dijkstra_q.at(i)->pull_name() == node_u->pull_name()){
                    dijkstra_q.erase(dijkstra_q.begin() + i); // remove u from Q
                }
            }
        }
        // cout << "node_u: " << node_u << endl;
        // cout << "node list[0]: " << dijkstra_q.at(0) << endl;
        // for(auto i:dijkstra_q){
        //     cout << i << endl;
        // }
        // cin >> edge_dist;
        
        temp_vector = node_u->pull_neighbors();
        for(auto i:temp_vector){
            for(auto j:dijkstra_q){
                if(i->pull_name() == j->pull_name()){
                    // alt = node_u.pulldist + edge_len(u to v)
                    for(auto k:my_graph->pull_graph_edge_list()){
                        if(*k->pull_source()->pull_name() == *i->pull_name() && *k->pull_end()->pull_name() == *j->pull_name()){
                            alt_dist = node_u->pull_distance() + k->pull_length();
                            break;
                        }
                    }
                    if(alt_dist < j->pull_distance()){
                        j->update_distance(alt_dist);
                        j->update_previous(i);
                        last_node = j;
                    }
                }
            }
        }
    }
    cout << "Dijkstra's algorithm ended at node " << last_node->pull_name() << " and the distance from the source node " << source_node->pull_name() << " is " << last_node->pull_distance() << endl;
    cout << "The path taken was: " << last_node->pull_name();
    node_u = last_node->pull_previous();
    while(true){
        cout << "<-" << node_u->pull_name();
        if(node_u->pull_previous() != nullptr){
            node_u = node_u->pull_previous();
        }
        else{
            break;
        }
    }
}

vector<Graph_edge *> sort_edges(vector<Graph_edge *> edge_vector){ // O(n^2)
    // return sorted vector of all edges from smallest to largest
    vector<Graph_edge *>edge_vector_copy;
    vector<Graph_edge *>sorted;
    int temp_edge;
    int len_val;

    edge_vector_copy = edge_vector;
    // for(auto edge:edge_vector_copy){
    while(edge_vector_copy.size() > 0){
        len_val = 9999;
        for(int edge_idx = 0; edge_idx < edge_vector_copy.size(); edge_idx++){
            // find smallest length
            if(edge_vector_copy.at(edge_idx)->pull_length() < len_val){
                len_val = edge_vector_copy.at(edge_idx)->pull_length();
                temp_edge = edge_idx;
            }
        }
        sorted.push_back(edge_vector_copy.at(temp_edge));
        edge_vector_copy.erase(edge_vector_copy.begin() + temp_edge);
    }
    return sorted;
}

std::set<string> MST_mutual_neighbors(Graph_node *node1, Graph_node *node2){ // O(n^2)
    std::set<string> mutual_neighbors;
    for(auto node1_neighbor:node1->pull_neighbors()){
        for(auto node2_neighbor:node2->pull_neighbors()){
            if(node1_neighbor->pull_name() == node2_neighbor->pull_name()){
                mutual_neighbors.insert(*node1_neighbor->pull_name());
            }
        }
    }
    return mutual_neighbors;
}

void run_min_span_tree(Graph *my_graph){ // O(n^4)
    vector<Graph_edge *> sorted_edge_list = sort_edges(my_graph->pull_graph_edge_list());
    vector<Graph_edge *> min_span_tree;
    vector<Graph_edge *> visited_edges;
    std::set<string> visited_nodes;
    std::set<string> visited_nodes_copy;
    std::set<string> mutual_neighbors;
    Graph_edge *temp_edge;
    string node_source;
    string node_end;
    string loop_check_source;
    string loop_check_end;
    bool node_source_check;
    bool node_end_check;
    int loop_warning;
    int total_dist;
    // std::pair<std::set<string>::iterator, bool> test_pair;

    for(auto edge:sorted_edge_list){
        loop_warning = 0;
        // temp_edge = edge;
        node_source = *edge->pull_source()->pull_name();
        node_end = *edge->pull_end()->pull_name();
        // visited_nodes.insert(node_source);
        // visited_nodes.insert(node_end);

        // node_source_check = false;
        // node_end_check = false;
        // for(auto node_name:visited_nodes){
        //     if(node_name == node_source){
        //         node_source_check = true;
        //     }
        //     else if(node_name == node_end){
        //         node_end_check = true;
        //     }
        // }
        // loop_warning = false;
        // if(node_source_check && node_end_check){
        //     loop_warning = true;
        // }
        // else{
        //     loop_warning = false;
        // }
        if(visited_edges.size() > 0){
            mutual_neighbors = MST_mutual_neighbors(edge->pull_source(), edge->pull_end());
            // cout << std::get<1>(test_pair) << endl;
            if(mutual_neighbors.size() > 0){
                // test_pair.first = mutual_neighbors.begin();
                // test_pair.second = false;
                for(auto i:mutual_neighbors){
                    for(auto loop_check:sorted_edge_list){ // is an edge to/from a mutual nbr in the visited_edges list?
                        if(loop_check != edge){ // make sure we're not comparing the same edge
                            loop_check_source = *loop_check->pull_source()->pull_name();
                            loop_check_end = *loop_check->pull_end()->pull_name();
                            if((loop_check_source == i ||loop_check_source == *edge->pull_source()->pull_name() ||loop_check_source == *edge->pull_end()->pull_name()) && (loop_check_end == i ||loop_check_end == *edge->pull_end()->pull_name() ||loop_check_end == *edge->pull_source()->pull_name())){
                                for(auto j:visited_edges){ // check if the mutual nbr's edge has been visited
                                    if(j->pull_source() != loop_check->pull_source() || j->pull_end() != loop_check->pull_end()){ // loop_check edge has not been visited
                                        // loop_warning = false;
                                        // loop_warning does not iterate
                                    }
                                    else{ // loop_check edge has been visited
                                        loop_warning++;
                                    }
                                }
                            }
                        }
                    }
                    // visited_nodes_copy = visited_nodes;
                    // test_pair = visited_nodes_copy.insert(i);
                    // if(test_pair.second == true){
                    //     // mutual neighbor has not been visited, source/end nodes' edge won't make a loop
                    //     // loop_warning = false;
                    //     // loop_warning does not iterate
                    // }
                    // else{ // test_pair.second == false
                    //     // mutual neighbor HAS been visited, source/end nodes' edge WILL make a loop
                    //     loop_warning++;
                    //     break;
                    // }
                }
            }
        }
        else{
            // loop_warning = false;
            // loop_warning does not iterate
        }


        if(loop_warning < 2){
            visited_edges.push_back(edge);
            // visited_nodes.insert(node_source);
            // visited_nodes.insert(node_end);
            min_span_tree.push_back(edge);
        }
    }
    cout << "Minimum Spanning Tree uses the following edges: " << endl;
    for(auto i:min_span_tree){
        cout << "Edge of length (" << i->pull_length() << ") from " << *i->pull_source()->pull_name() << " to " << *i->pull_end()->pull_name() << endl;
        total_dist += i->pull_length();
    }
    cout << "Total distance: " << total_dist << endl;
}

void create_graph(Graph *my_graph, vector<string> starter_names){ // O(n)
    for(auto i:starter_names){
        my_graph->add_graph_node(i);
    }
    // // Aaron -> Brad
    my_graph->add_graph_edge(get_rand_length(), my_graph->pull_graph_node_list().at(0), my_graph->pull_graph_node_list().at(1));
    // my_graph->add_graph_edge(10, my_graph->pull_graph_node_list().at(0), my_graph->pull_graph_node_list().at(1));
    // // Aaron -> Charlie
    my_graph->add_graph_edge(get_rand_length(), my_graph->pull_graph_node_list().at(0), my_graph->pull_graph_node_list().at(2));
    // my_graph->add_graph_edge(2, my_graph->pull_graph_node_list().at(0), my_graph->pull_graph_node_list().at(2));
    // // Brad -> Charlie
    my_graph->add_graph_edge(get_rand_length(), my_graph->pull_graph_node_list().at(1), my_graph->pull_graph_node_list().at(2));
    // my_graph->add_graph_edge(7, my_graph->pull_graph_node_list().at(1), my_graph->pull_graph_node_list().at(2));
    // // Charlie -> David
    my_graph->add_graph_edge(get_rand_length(), my_graph->pull_graph_node_list().at(2), my_graph->pull_graph_node_list().at(3));
    // my_graph->add_graph_edge(3, my_graph->pull_graph_node_list().at(2), my_graph->pull_graph_node_list().at(3));
    // // Charlie -> Erin
    my_graph->add_graph_edge(get_rand_length(), my_graph->pull_graph_node_list().at(2), my_graph->pull_graph_node_list().at(4));
    // my_graph->add_graph_edge(6, my_graph->pull_graph_node_list().at(2), my_graph->pull_graph_node_list().at(4));
    // // David -> Erin
    my_graph->add_graph_edge(get_rand_length(), my_graph->pull_graph_node_list().at(3), my_graph->pull_graph_node_list().at(4));
    // my_graph->add_graph_edge(1, my_graph->pull_graph_node_list().at(3), my_graph->pull_graph_node_list().at(4));
}

string print_node_names(Graph *my_graph){ // O(n)
    string node_list;
    for(auto i:my_graph->pull_graph_node_list()){
        node_list += *i->pull_name() + ", ";
    }
    return node_list;
}

vector<string> compile_vector_graphnode_to_string(vector<Graph_node *> graph_node_list){ // O(n)
    vector<string> current_graph_node_list;
    for(auto i:graph_node_list){
        current_graph_node_list.push_back(*i->pull_name());
    }
    return current_graph_node_list;
}

void pretty_print(Graph *my_graph){ // O(n^2)
    for(auto i:my_graph->pull_graph_node_list()){
        cout << "Node name: " << *i->pull_name() << endl;
        string neighborhood = {};
        for(auto j:i->pull_neighbors()){
            neighborhood += *j->pull_name();
            neighborhood += " ";
        }
        cout << "Node neighbors (" << i->pull_neighbors().size() << "): " << neighborhood << endl;
    }
    for(auto i:my_graph->pull_graph_edge_list()){
        cout << "Edge of length (" << i->pull_length() << ") from " << *i->pull_source()->pull_name() << " to " << *i->pull_end()->pull_name() << endl;
    }
}

int main(int argc, char **argv){ // O(n^2)
    srand(time(NULL));
    int esc_val = 1;
    string menu_input;
    int menu_select;

    string node_name;
    vector<string>::iterator it_node_name;

    string edge_input;
    int edge_value;
    string source_input;
    string end_input;
    vector<string> current_graph_node_list;
    vector<string>::iterator it_node1;
    vector<string>::iterator it_node2;
    int node1_index;
    int node2_index;
    Graph_node *temp_node1;
    vector<Graph_node *> neighbor_list;
    vector<string> neighbor_list_string;

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
    cout << "Current graph: " << endl;
    pretty_print(my_graph);

    // print_node_names(my_graph);

    while(esc_val){ // main menu
        cout << "What would you like to do? [1]:Add a node. [2]:Add an edge. [3]:Print all graph objects. [4]:Run Dijkstra's algorithm (shortest path algorithm). [5]:Run minimum spanning tree algorithm. [6]:Exit." << endl;
        cin >> menu_input;
        try{
            menu_select = std::stoi(menu_input);
        }
        catch(...){ // (...)<-catches all exceptions. will loop to start of main menu if int cast throws
            cout << menu_input << " is not a valid entry. Try again." << endl;
            continue;
        }
        switch(menu_select){
            case 1: // add a node
                current_graph_node_list = compile_vector_graphnode_to_string(my_graph->pull_graph_node_list());
                while(true){
                    cout << "Enter the name you want to assign to the new node. Your options are: " << print_node_names(my_graph) << endl;
                    cin >> node_name;
                    it_node_name = find(current_graph_node_list.begin(), current_graph_node_list.end(), node_name);
                    if(it_node_name == current_graph_node_list.end()){
                        break;
                    }
                    else{
                        cout << "Sorry, that name already exists. Try again." << endl;
                    }
                }
                add_node(my_graph, node_name);
                continue;
            case 2: // add an edge
                current_graph_node_list = compile_vector_graphnode_to_string(my_graph->pull_graph_node_list());
                // current_graph_node_list = my_graph->pull_graph_node_list();
                while(true){
                    cout << "Enter the length of the edge, max of 100 (int required): " << endl;
                    cin >> edge_input;
                    try{
                        edge_value = std::stoi(edge_input);
                    }
                    catch(...){
                        cout << edge_input << " is not an integer. Try again." << endl;
                        continue;
                    }
                    if(edge_value > 100){
                        cout << edge_value << " is greater than the max of 100. Try again." << endl;
                        continue;
                    }
                    break;
                }
                while(true){
                    cout << "Enter the name of the node you want to start the edge at. Your options are: " << print_node_names(my_graph) << endl;
                    cin >> source_input;
                    cout << "Enter the name of the node you want to end the edge at. You cannot choose the same node a second time. Your options are: " << print_node_names(my_graph) << endl;
                    cin >> end_input;
                    it_node1 = std::find(current_graph_node_list.begin(), current_graph_node_list.end(), source_input);
                    it_node2 = std::find(current_graph_node_list.begin(), current_graph_node_list.end(), end_input);
                    if(it_node1 != current_graph_node_list.end()){
                        if(it_node2 != current_graph_node_list.end()){
                            if(it_node1 != it_node2){
                                break;
                            }
                            else{
                                cout << "You cannot select the same node twice. Try again." << endl;
                                continue;
                            }
                        }
                        else{
                            cout << end_input << " is not a valid option. Try again." << endl;
                            continue;
                        }
                    }
                    else{
                        cout << source_input << " is not a valid option. Try again." << endl;
                        continue;
                    }
                }
                node1_index = it_node1 - current_graph_node_list.begin();
                node2_index = it_node2 - current_graph_node_list.begin();

                temp_node1 = my_graph->pull_graph_node_list().at(node1_index); // set temp_node1 = the node the edge starts at
                neighbor_list = temp_node1->pull_neighbors();
                neighbor_list_string = compile_vector_graphnode_to_string(neighbor_list);
                it_node_name = find(neighbor_list_string.begin(), neighbor_list_string.end(), end_input); // check if edge end node is in list of neighbors for edge source node
                if(it_node_name != neighbor_list_string.end()){ // if the 2 nodes are already neighbors, loop and try again.
                    cout << "Sorry, this edge already exists. Try again." << endl;
                    continue;
                }
                add_edge(my_graph, edge_value, node1_index, node2_index);
                continue;
            case 3: // pretty print graph
                pretty_print(my_graph);
                continue;
            case 4: // run dijkstra's
                cout << "Enter the name of the node you want to start the edge at. Your options are: " << print_node_names(my_graph) << endl;
                cin >> source_input;
                it_node1 = std::find(current_graph_node_list.begin(), current_graph_node_list.end(), source_input);
                node1_index = it_node1 - current_graph_node_list.begin();
                temp_node1 = my_graph->pull_graph_node_list().at(node1_index);
                run_dijkstras(my_graph, temp_node1);
                continue;
            case 5: // run minimum spanning tree
                run_min_span_tree(my_graph);
                continue;
            case 6: // exit
                
                cout << "You have chosen to exit the program. Goodbye." << endl;
                esc_val--;
                break;
            default: // why are you here?
                
                cout << "Sorry, " << menu_select << " is not a valid selection. Please try again." << endl;
                continue;
        }
    }


    return 0;
}
    // if(my_graph.pull_graph_node_list().size() >= 2){

    // }


    // if(graph_node_list.size() >= 2){
    //            add_graph_edge(edge_length, edge_source, edge_end);
    //         }
    //         else{
    //             cout << "You only have " << graph_node_list.size() << " node(s) in the graph. You must add " << (2-graph_node_list.size()) << " more node(s) in order to create an edge." << endl;
    //         }
    // my_graph.add_graph_node("Michael");

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