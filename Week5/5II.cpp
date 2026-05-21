// Week5 - (Ques 2) : "2Sum" T[n] = O(n) 

#include<bits/stdc++.h>
using namespace std;

pair<int, int> twoSum(vector<int>& arr, int target){
    unordered_map<int, int>map;
    int n = arr.size();
    for(int i = 0; i<n; i++){
        int y = target - arr[i];
        if(map.find(y)!=map.end())
            return {map[y], i};
        map[arr[i]] = i;
    }
    return {-1, -1};
}

// Approach 2 using sorting T[n] = O(nlogn) 
pair<int, int> twoSum(vector<int>&arr, int key){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    
    for(int i = 0, j=n-1; i<j;){
        int sum = arr[i] + arr[j];
        if(sum==key) return {arr[i], arr[j]};
        else if(sum>key) j--;
        else i++;
    }
    return {-1, -1};
}

int main(){
    int t = 0;
    cout<<"Enter the number of the trials : ";
    cin>>t;
    while(t--){
        int n;
        cout<<"Enter the size of arr : ";
        cin>>n;
        vector<int>arr(n);
        cout<<"Enter the elements of the arr : ";
        for(int i = 0; i<n; i++)
            cin>>arr[i];
        int target = 0;
        cout<<"Enter the target : ";
        cin>>target;
        pair<int,int>p = twoSum(arr, target);
        if(p.first == -1)
            cout<<"No pair exists!";
        else 
            cout<<"Pair index are : "<<p.first<<" "<<p.second<<endl;
    }
}
