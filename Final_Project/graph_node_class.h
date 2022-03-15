#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Graph_node{
    private:
        string name;
        vector<Graph_node *> neighbors;

    public:
        Graph_node(string name, vector<Graph_node *> neighbors){ // instead of listing neighbors here, make class for edges and have edges have pointers to nodes
            this->name = name;
            this->neighbors = neighbors;
        }
        string *pull_name(){
            return &name;
        }
        vector<Graph_node *> pull_neighbors(){
            cout << "neighbors size = " << neighbors.size() << endl;
            return neighbors;
        }
        void set_neighbor(Graph_node *end_node){
            neighbors.push_back(end_node);
        }
};