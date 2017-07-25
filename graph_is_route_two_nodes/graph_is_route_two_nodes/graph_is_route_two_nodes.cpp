/*
 
 4.1 Route Between Nodes: Given a directed graph, design an algorithm to find out whether there is a route between two nodes.
 
 Hints:
 
 #127 Two well-known algorithms can do this.  What are the tradesoffs between them?
 
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

template<class T>
class Node{
public:
    Node(T val) : val{val} {}

    T GetValue() { return val; }
    
    vector<Node<T>*> GetAdjacentNodes() { return adjacent_nodes; }
    
    void AddAdjacencyTo(Node<T>* node){
        adjacent_nodes.push_back(node);
    }
    
    void RemoveAdjacencyTo(Node<T>* node){
        
        typedef typename vector<Node<T>*>::iterator node_ptr_itr;
        for (node_ptr_itr itr=adjacent_nodes.begin(); itr< adjacent_nodes.end(); itr++){
            if (*itr == node){
                adjacent_nodes.erase(itr);
                return;
            }
        }
    }

private:
    T val;
    vector<Node<T>*> adjacent_nodes;
};



class Graph{
public:
    Graph() {}
    
    template<class T>
    static bool IsRouteViaBFS(Node<T>* start, Node<T>* target, int& iteration_count){
        
        // reset count
        iteration_count = 0;
        
        // queue is used for BFS to search through immediate neighbors first
        queue<Node<T>*> q;
        
        // visited hash map, key is the address of the pointer to the Node<T>
        unordered_map<Node<T>*,bool> visited;
        
        // insert start node into queue and mark as visited
        q.push(start);
        visited[start]=true;
        
		/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

         while the queue is not empty, dequeue node and check if it is target
         
         then check immediate neighbors for target
         by adding the immediate neighbors onto the queue
         and marking them as visited
         
         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
        while (!q.empty()){
        
            // dequeue node and check if it is target
            Node<T>* curr = q.front();
            if (curr == target){
                return true; // target found
            }
            q.pop();
            
            // check each non-visited neighbor
            vector<Node<T>*> neighbors = curr->GetAdjacentNodes();
            for (auto n : neighbors){
                if (!visited[n]){
                    visited[n]=true;
                    q.push(n);
                }
                iteration_count++;
            }
        }
        
        // BFS is exhausted without finding target
        return false;
    }
};

int main(int argc, const char * argv[]) {

    
    Node<int>* node1 = new Node<int>{1};
    Node<int>* node2 = new Node<int>{2};
    Node<int>* node3 = new Node<int>{3};
    Node<int>* node4 = new Node<int>{4};
    Node<int>* node5 = new Node<int>{5};

    /*
     
     1's neighbors: 2,3,4,5
     2's neighbors: 3,4,5
     3's neighbors: 4,5
     
     */
    
    node1->AddAdjacencyTo(node2);
    node1->AddAdjacencyTo(node3);
    node1->AddAdjacencyTo(node4);
    node1->AddAdjacencyTo(node5);

    node2->AddAdjacencyTo(node3);
    node2->AddAdjacencyTo(node4);
    node2->AddAdjacencyTo(node5);
    
    node3->AddAdjacencyTo(node4);
    node3->AddAdjacencyTo(node5);
    
    node4->AddAdjacencyTo(node5);
    

    int iterations = 0;
    bool found = Graph::IsRouteViaBFS(node1,node5,iterations);
    
    if (found){
        cout << "Found in " << iterations << " iterations." << endl << endl;
    } else {
        cout << "Not found in " << iterations << " iterations." << endl << endl;
    }
    
    
    
    return 0;
}
