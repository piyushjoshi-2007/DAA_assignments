// Week6 (Ques 3) Part B : Cycle Detection in Directed Graph

#include<bits/stdc++.h>
using namespace std;

bool directeddfs(int src, vector<vector<int>>&adj, vector<int>&vst, vector<int>&path){
    vst[src] = 1;
    path[src] = 1;
    for(auto ngh : adj[src]){
        if(!vst[ngh]){
            if(directeddfs(ngh, adj, vst, path))
                return true;
        }
        else if(path[ngh]) return true;
    }
    path[src] = 0;
    return false;
}

void cycleDetectionDirected(vector<vector<int>>&adj, int V){
    vector<int>visited(V, 0);
    vector<int>pathvst(V, 0);
    for(int i=0; i<V; i++){
        if(!visited[i]){
            if(directeddfs(i, adj, visited, pathvst)){
                cout<<"Cyclic Graph"<<endl;
                return;
            }
        }
    }
    cout<<"Acyclic Directed Graph"<<endl;
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
    }
    
    cycleDetectionDirected(adj, V);
}