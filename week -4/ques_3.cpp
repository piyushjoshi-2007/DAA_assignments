/*
3️⃣ Question: Kth Smallest Element
Problem Statement

Given an unsorted array, design an algorithm to find the Kth smallest element in the array.

If Kth element does not exist print:

not present
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int T;
    cin>>T;

    while(T--){

        int n;
        cin>>n;

        vector<int> arr(n);

        for(int i=0;i<n;i++)
            cin>>arr[i];

        int k;
        cin>>k;

        sort(arr.begin(),arr.end());

        if(k<=n)
            cout<<arr[k-1]<<endl;
        else
            cout<<"not present"<<endl;
    }
}
