// Week11 (Ques 1) : Matrix chain multiplication T[n] = O(n^3)

#include<bits/stdc++.h>
using namespace std;

int matrixMultiplication(int arr[], int n){
    
    vector<vector<int>>dp(n, vector<int>(n, 0));
    
    for(int len = 2; len<n; len++){
        for(int i = 1; i<= n-len; i++){
            int j = i + len- 1;
            dp[i][j] = INT_MAX;
            for(int k = i; k<j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j]);
            }
        }
    }
    
    return dp[1][n-1];
}

int main(){
    int n;
    cin>>n;
    
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    int steps = matrixMultiplication(arr, n);
    
    cout<<"The number of the steps are : "<<steps<<endl;
}