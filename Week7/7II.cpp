// Week7 Ques(2) : BellmanFord O(V(V+E))

#include<bits/stdc++.h>
using namespace std;

bool BellmanFord(int src, vector<vector<int>>& edges,
                 vector<int>& parent, vector<int>& dist, int V){

    dist[src] = 0;

    // Relax edges V-1 times
    for(int i = 0; i < V-1; i++){
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(dist[u] != INT_MAX && dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    // Check for negative cycle
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if(dist[u] != INT_MAX && dist[v] > dist[u] + w){
            return true; // negative cycle exists
        }
    }

    return false;
}

void printPath(vector<int>& parent, int node){
    if(parent[node] == -1){
        cout << node;
        return;
    }
    printPath(parent, parent[node]);
    cout << " -> " << node;
}

int main(){
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges;

    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back({u, v, w});
        edges.push_back({v, u, w}); // remove if directed
    }

    int src;
    cin >> src;

    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);

    if(BellmanFord(src, edges, parent, dist, V)){
        cout << "Negative weight cycle exists\n";
        return 0;
    }

    for(int i = 0; i < V; i++){
        cout << "Node " << i << ":\n";

        if(dist[i] == INT_MAX){
            cout << "No path\n";
            continue;
        }

        cout << "Distance: " << dist[i] << endl;
        cout << "Path: ";
        printPath(parent, i);
        cout << endl;
    }
}