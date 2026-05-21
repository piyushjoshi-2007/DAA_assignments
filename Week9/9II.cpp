# Week9 (Ques 2) : Fractional Knapsack Implementation T[n] = O(nlogn)

#include<bits/stdc++.h>
using namespace std;

void fractionalKnapsack(vector<int>& val, vector<int>& wt, int W, vector<vector<double>>& list){
    
    priority_queue<pair<double, int>> pq;

    for(int i = 0; i < val.size(); i++){
        double ratio = (double)val[i] / wt[i];
        pq.push({ratio, i});
    }

    while(!pq.empty() && W > 0){
        auto it = pq.top();
        pq.pop();

        int index = it.second;
        int weight = wt[index];
        double ratio = it.first;

        if(weight <= W){
            list.push_back({(double)index, (double)weight, (double)val[index]});
            W -= weight;
        }
        else{
            list.push_back({(double)index, (double)W, ratio * W});
            W = 0;
        }
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> val(n), wt(n);

    for(int i = 0; i < n; i++) cin >> wt[i];
    for(int i = 0; i < n; i++) cin >> val[i];

    int W;
    cin >> W;

    vector<vector<double>> list;

    fractionalKnapsack(val, wt, W, list);

    double total = 0;

    for(auto item : list){
        total += item[2];
        cout << "Item " << item[0] + 1 
             << " Weight: " << item[1] 
             << " Value: " << item[2] << endl;
    }

    cout << "Maximum Value: " << total << endl;

    return 0;
}