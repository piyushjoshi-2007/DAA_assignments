// Activity Selection T[n] = O(nlogn)

#include<bits/stdc++.h>
using namespace std;

void activitySelection(vector<int>& st, vector<int>& ft, int n){
    
    // Min heap based on finish time
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    for(int i = 0; i < n; i++){
        pq.push({ft[i], i});
    }

    // First activity
    auto first = pq.top();
    pq.pop();

    int index = first.second;
    int lastFinish = ft[index];

    cout << "Activity " << index + 1 
         << " Start: " << st[index] 
         << " Finish: " << ft[index] << endl;

    int activities = 1;

    // Process remaining
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int index = it.second;

        if(st[index] >= lastFinish){
            cout << "Activity " << index + 1 
                 << " Start: " << st[index] 
                 << " Finish: " << ft[index] << endl;

            lastFinish = ft[index];
            activities++;
        }
    }

    cout << "Total activities: " << activities << endl;
}

int main(){
    int n;
    cin >> n;

    vector<int> st(n), ft(n);

    for(int i = 0; i < n; i++){
        cin >> st[i] >> ft[i];
    }

    activitySelection(st, ft, n);

    return 0;
}