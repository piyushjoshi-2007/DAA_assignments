// Week10 (Ques3) : Majority(x>n/2) T[n] = O(n) + Median using quickSelect T[n] = Avg(nlogn)

#include<bits/stdc++.h>
using namespace std;

// ---------- PARTITION ----------
int partition(int arr[], int start, int end){
    int pivot = arr[end];
    int i = start - 1;

    for(int j = start; j < end; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[end]);
    return i+1;
}

// ---------- QUICKSELECT ----------
int quickSelect(int arr[], int start, int end, int k){
    if(start <= end){
        int p = partition(arr, start, end);

        if(p == k) return arr[p];
        else if(p > k) return quickSelect(arr, start, p-1, k);
        else return quickSelect(arr, p+1, end, k);
    }
    return -1;
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // -------------------------
    // Majority (Boyer-Moore)
    // -------------------------
    int count = 0, ele = 0;

    for(int i = 0; i < n; i++){
        if(count == 0){
            ele = arr[i];
            count = 1;
        }
        else if(arr[i] == ele){
            count++;
        }
        else{
            count--;
        }
    }

    // verify
    int freq = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == ele) freq++;
    }

    if(freq > n/2) cout << "yes\n";
    else cout << "no\n";

    // -------------------------
    // Median
    // -------------------------
    if(n % 2 == 1){
        cout << quickSelect(arr, 0, n-1, n/2);
    }
    else{
        int a = quickSelect(arr, 0, n-1, n/2 - 1);
        int b = quickSelect(arr, 0, n-1, n/2);
        cout << (a + b) / 2.0;
    }

    return 0;
}