#include <bits/stdc++.h>
using namespace std;

int main(){
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adjMat(V, vector<int>(V, INT_MAX));

    // initialize diagonal
    for(int i = 0; i < V; i++) adjMat[i][i] = 0;

    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adjMat[u][v] = w;
        adjMat[v][u] = w; // remove if directed
    }

    int k;
    cin >> k;

    vector<vector<int>> dp(k + 1, vector<int>(V, INT_MAX));

    int src;
    cin >> src;

    dp[0][src] = 0;

    for(int i = 1; i <= k; i++){
        for(int u = 0; u < V; u++){
            if(dp[i-1][u] == INT_MAX) continue;

            for(int v = 0; v < V; v++){
                if(adjMat[u][v] != INT_MAX){
                    dp[i][v] = min(dp[i][v],
                                   dp[i-1][u] + adjMat[u][v]);
                }
            }
        }
    }

    int dest;
    cin >> dest;

    if(dp[k][dest] == INT_MAX) cout << -1;
    else cout << dp[k][dest];
}