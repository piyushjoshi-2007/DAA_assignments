/* Question 2: Binary Search

Problem Statement:
Given an already sorted array of positive integers, 
design an algorithm and implement it using a program to find whether the given key element
is present in the array or not. Also find the total number of comparisons required to search the key element.

Time Complexity:
O(log n) */


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

        int low = 0, high = n - 1;
        int comparisons = 0;
        bool found = false;

        while(low <= high) {
            int mid = (low + high) / 2;
            comparisons++;

            if(arr[mid] == key) {
                found = true;
                break;
            }
            else if(arr[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        }

        if(found)
            cout << "Present " << comparisons << endl;
        else
            cout << "Not Present " << comparisons << endl;
    }
}



