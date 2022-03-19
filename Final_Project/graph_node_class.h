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
        int distance;
        Graph_node *previous;
        bool visited;

    public:
        // instead of listing neighbors here, make class for edges and have edges have pointers to nodes
        Graph_node(string name, vector<Graph_node *> neighbors, int distance, Graph_node *previous, bool visited){ // O(1)
            this->name = name;
            this->neighbors = neighbors;
            this->distance = distance;
            this->previous = previous;
            this->visited = visited;
        }
        string *pull_name(){ // O(1)
            return &name;
        }
        vector<Graph_node *> pull_neighbors(){ // O(1)
            // cout << "neighbors size = " << neighbors.size() << endl;
            return neighbors;
        }
        void set_neighbor(Graph_node *end_node){ // O(1)
            neighbors.push_back(end_node);
        }
        int pull_distance(){ // O(1)
            return distance;
        }
        void update_distance(int new_distance){ // O(1)
            this->distance = new_distance;
        }
        Graph_node *pull_previous(){ // O(1)
            return previous;
        }
        void update_previous(Graph_node *new_previous){ // O(1)
            this->previous = new_previous;
        }
        bool pull_visited(){ // O(1)
            return visited;
        }
        void update_visited(bool visit){ // O(1)
            this->visited = visit;
        }
};