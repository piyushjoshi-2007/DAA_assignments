/* Question 1: Linear Search

Problem Statement:

Given an array of non-negative integers, 
design a linear algorithm and implement it using a program to find whether a given key element 
is present in the array or not. Also find the total number of comparisons required to search the key element.

Time Complexity:
O(n) */


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        int key;
        cin >> key;

        int comparisons = 0;
        bool found = false;

        for(int i = 0; i < n; i++) {
            comparisons++;
            if(arr[i] == key) {
                found = true;
                break;
            }
        }

        if(found)
            cout << "Present " << comparisons << endl;
        else
            cout << "Not Present " << comparisons << endl;
    }
}
