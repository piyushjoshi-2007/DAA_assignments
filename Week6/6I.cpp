// to find if a path exists between two given vertices or not. T[n] = O(V+E)

#include<bits/stdc++.h>
using namespace std;

bool dfs(int src, int des, vector<vector<int>>&adj, vector<bool>&visited){
    visited[src] = true;

    if(src == des) return true;

    for(auto edge : adj[src]){
        if(!visited[edge]){
            if(dfs(edge, des, adj, visited))
                return true;
        }
    }
    return false;
}

int main(){
    int V;
    cout<<"Enter the nodes : ";
    cin>>V;

    vector<vector<int>> adj(V);

    int E;
    cout<<"Enter number of edges : ";
    cin>>E;

    cout<<"Enter the edges : ";
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<"Enter the nodes to check path : ";
    int e1, e2;
    cin>>e1>>e2;

    vector<bool> visited(V, false);

    if(dfs(e1, e2, adj, visited)){
        cout<<"Path exists!"<<endl;
    }
    else{
        cout<<"Path doesn't exist!"<<endl;
    }
}