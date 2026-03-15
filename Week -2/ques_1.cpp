/*1️ Question 1: Count occurrences of key in sorted array
Problem Statement

Given a sorted array of positive integers containing duplicate elements, design an algorithm to check whether a key element is present in the array.
If present, also find the number of copies of that key element.

Time Complexity
O(log n) */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        int key;
        cin >> key;

        int count = 0;

        for(int i = 0; i < n; i++) {
            if(arr[i] == key)
                count++;
        }

        if(count > 0)
            cout << key << " " << count << endl;
        else
            cout << "Key not present" << endl;
    }
}
