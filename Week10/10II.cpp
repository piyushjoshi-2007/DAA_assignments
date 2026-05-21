# 

#include<bits/stdc++.h>
using namespace std;

void jobSequencing(vector<int>& time, vector<int>& deadline){
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    for(int i = 0; i < time.size(); i++){
        pq.push({deadline[i], i});
    }
    
    int currentTime = 0;
    vector<int> selected;

    // First task
    auto first = pq.top();
    pq.pop();

    currentTime += time[first.second];
    selected.push_back(first.second + 1);

    int tasks = 1;

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        
        int index = it.second;
        
        if(currentTime + time[index] <= deadline[index]){
            tasks++;
            currentTime += time[index];
            selected.push_back(index + 1);
        }
    }

    cout << "Max number of tasks = " << tasks << endl;
    
    cout << "Selected task numbers: ";
    for(int x : selected){
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    
    vector<int> time(n), deadline(n);
    
    for(int i = 0; i < n; i++){
        cin >> time[i] >> deadline[i];
    }
    
    jobSequencing(time, deadline);
}