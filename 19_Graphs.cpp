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

// BFS Traversal - 
/*
T.C = O(n + m)    ; n = no. of vertex, m = no. of edges 

#include <bits/stdc++.h> 

void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges){
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        //store frontNOde into ans
        ans.push_back(frontNode);

        //traverse all neighbors of frontNOde
        for(auto i:adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    // traverse all component of a graph
    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}

*/

// DFS Traversal
// T.C = O(n+m)     ; n = no. of vertex, m = no. of edges 
/*

#include <bits/stdc++.h>

void dfs(int node, unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &component){
    // ans store
    component.push_back(node);
    
    // mark visited
    visited[node] = 1;

    // har connected node ke liye recursive call
    for(auto i:adjList[node]){
        if(!visited[i]){
            dfs(i, adjList, visited, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // prepare adjacency list
    unordered_map<int, set<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
    
    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    // traverse all component of a graph
    for(int i=0; i<V; i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i, adjList, visited, component);
            ans.push_back(component);
        }
    }

    return ans;
}

*/
