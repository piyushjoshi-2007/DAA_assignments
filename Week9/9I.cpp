// Week9 (Ques 1) : Implemenatation of Floyd-Warshall O(V^3)

#include<bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>>& dist, int V){
    
    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    // 🔴 Negative Cycle Detection
    for(int i = 0; i < V; i++){
        if(dist[i][i] < 0){
            cout << "Negative cycle detected!" << endl;
            return;
        }
    }
    
    // ✅ Print Result Matrix
    cout << "\nShortest Distance Matrix:\n";
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int V, E;
    cin >> V >> E;

    vector<vector<int>> dist(V, vector<int>(V, INT_MAX));
    
    // 🔹 Initialize diagonal
    for(int i = 0; i < V; i++){
        dist[i][i] = 0;
    }

    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;

        dist[u][v] = w;
        dist[v][u] = w; // remove if directed graph
    }

    floydWarshall(dist, V);
}