#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

// adjacency list representation

template<class T>

class graph{
    public:
     
    unordered_map<T, list<T>> adj;
    
    void addEdge(int u, int v, bool dir){
        // dir = 0 -> undirected
        // dir = 1 -> directed
        
        //create an edge from u to v
        adj[u].push_back(v);
        if(dir == 0){
            adj[v].push_back(u);
        }
    }
    
    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<<"-> ";
            for(auto j: i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    graph<int> g;
    int n,m;
    
    cout<<"Enter no. of nodes : ";
    cin>>n;
    cout<<"Enter no. of edges : ";
    cin>>m;
    
    cout<<"Enter the nodes - "<<endl;
    
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        
        g.addEdge(u, v, 0);
    }
    
    
    g.printAdjList();

    return 0;
}
