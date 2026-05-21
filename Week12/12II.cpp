// Week12 (Ques 2) : 0/1 Knapsack T[n] = O(nW)

#include<bits/stdc++.h>
using namespace std;

int knapsack(int n, vector<int>& wt, vector<int>& val, int W){
    
    vector<vector<int>>dp(n+1, vector<int>(W+1, 0));
    
    for(int i = 1; i<=n; i++){
        int weight = wt[i-1];
        int value = val[i-1];
        for(int j = 1; j<=W; j++){
            if(weight<=j){
                dp[i][j] = max(dp[i-1][j], value + dp[i-1][j - weight]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main(){
    int n;
    cin>>n;
    
    vector<int>wt(n, 0);
    vector<int>val(n, 0);
    
    for(int i = 0; i<n; i++){
        cin>>wt[i]>>val[i];
    }
    
    int W;
    cin>>W;
    
    int total = knapsack(n, wt, val, W);
    
    cout<<"The total value : "<<total<<endl;
    
}