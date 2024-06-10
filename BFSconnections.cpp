#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph{
    int V; // Num of vertices
    vector<vector<int>> adj; // Adj matrix list

public:
    Graph(int V){
        this->V = V;
        adj.assign(V, vector<int>(V, 0)); // Initialize adjacency matrix from 0
    }
    void addEdge(int a, int b){
        adj[a][b] = 1;
        adj[b][a] = 1; // For undirected graph, edge from b to a 
    }
    void BFS(int start, vector<bool>& visited){
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while(q.empty()==false){
            int node= q.front();
            cout<<node<< " ";
            q.pop();

            for(int i = 0; i < V; ++i){   // Exploring all adjacent nodes of a node
                if(adj[node][i] == 1 && visited[i]==false){
                    q.push(i);
                    visited[i] = true;
                }}}
            }
    int connectedComponents() {
        int counter = 0;
        vector<bool> visited(V,false); // Initialize all vertices as not visited
        for(int i=0; i<V;i++) {
            if(visited[i]==false){
                cout<<"Component "<<counter<< ": ";
                BFS(i,visited);
                cout<<endl;
                counter++;
            }
        }   return counter;
    }
};

int main(){
    Graph g(5); // Create a graph with 5 vertices
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(3,4); // Isolated nodes

    cout<<"Number of connected components: "<< g.connectedComponents()<<endl;
    return 0;
}
