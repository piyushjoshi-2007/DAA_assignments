// Week6 (Ques 3) Part a : Cycle Detection in Undirected Graph

#include<bits/stdc++.h>
using namespace std;

bool dfs(int src, int parent, vector<vector<int>>&adj, vector<int>&visited){
    visited[src] = 1;
    for(auto ngh : adj[src]){
        if(!visited[ngh]){
            if(dfs(ngh, src, adj, visited))
                return true;
        }
        else if(ngh != parent) return true;
    }
    return false;
}

void cycleDetection(vector<vector<int>>&adj, int V){
    vector<int>visited(V, 0);
    for(int i = 0; i<V; i++){
        if(!visited[i]){
            if(dfs(i, -1, adj, visited)){
                cout<<"Cycle Exists."<<endl;
                return;
            }
        }
    }
    cout<<"Acyclic Graph"<<endl;
}


int main(){
    int V;
    cin>>V;
    int E;
    cin>>E;
    vector<vector<int>>adj(V);
    for(int i = 0; i<E; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    cycleDetection(adj, V);
}