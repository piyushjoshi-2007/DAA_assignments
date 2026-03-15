/*

3️⃣ Question: Check Duplicate Elements
Problem Statement

Given an unsorted array of positive integers, design an algorithm to find whether duplicate elements exist or not using sorting.

Output:

YES

if duplicates exist otherwise

NO
Time Complexity - 
O(n log n)
*/

#include <iostream>
#include <vector>
#include <algorithm>
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

        sort(arr.begin(), arr.end());

        bool duplicate = false;

        for(int i = 1; i < n; i++) {

            if(arr[i] == arr[i-1]) {
                duplicate = true;
                break;
            }
        }

        if(duplicate)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
