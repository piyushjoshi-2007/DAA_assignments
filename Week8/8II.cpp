// Week8 (Ques 2) : Kruskal's Implementation T[n] = O(V+E(logV))

#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int w, u, v;
};

bool cmp(Edge a, Edge b){
    return a.w < b.w;
}

class DSU{
public:
    vector<int> Parent, Rank;

    DSU(int n){
        Parent.resize(n);
        Rank.resize(n, 0);
        for(int i = 0; i < n; i++){
            Parent[i] = i;
        }
    }

    int findParent(int x){
        if(Parent[x] != x){
            Parent[x] = findParent(Parent[x]);
        }
        return Parent[x];
    }

    void unionSet(int u, int v){
        int a = findParent(u);
        int b = findParent(v);

        if(a == b) return;

        if(Rank[a] > Rank[b]) Parent[b] = a;
        else if(Rank[b] > Rank[a]) Parent[a] = b;
        else{
            Parent[b] = a;
            Rank[a]++;
        }
    }
};

int main(){
    int V, E;
    cin >> V >> E;

    vector<Edge> Edges;

    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        Edges.push_back({w, u, v});
    }

    sort(Edges.begin(), Edges.end(), cmp);

    DSU dsu(V);

    int mstWeight = 0;
    int edgeCount = 0;

    for(auto edge : Edges){
        int u = edge.u;
        int v = edge.v;

        if(dsu.findParent(u) != dsu.findParent(v)){
            dsu.unionSet(u, v);
            mstWeight += edge.w;
            edgeCount++;

            if(edgeCount == V - 1) break;
        }
    }

    cout << "Minimum Spanning Weight: " << mstWeight << endl;

    return 0;
}