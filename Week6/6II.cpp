// Week6 (Ques 2) : Bipartite Graph 

#include<bits/stdc++.h>
using namespace std;

bool dfs(int src, int parent, vector<vector<int>>&adj, vector<int>&color){
    color[src] = (parent == 1)?-1:1;
    for(auto ngh : adj[src]){
        if(!color[ngh]){
            if(!dfs(ngh, color[src], adj, color))
                return false;
        }
        else if(color[ngh] == color[src]) return false;
    }
    return true;
}

void bipartite(vector<vector<int>>&adj, int V){
    vector<int>color(V, 0);
    for(int i = 0; i<V; i++){
        if(!color[i]){
            if(!dfs(i, -1, adj, color)){
                cout<<"Not a Bipartite!"<<endl;
                return;
            }
        }
    }
    cout<<"The graph is Bipartite"<<endl;
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
    
    bipartite(adj, V);
}