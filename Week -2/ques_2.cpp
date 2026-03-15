/*2️⃣ Question 2: Find indices i, j, k such that
arr[i] + arr[j] = arr[k]
Problem Statement

Given a sorted array of positive integers, design an algorithm to find three indices i, j, k such that

arr[i] + arr[j] = arr[k]

If such indices exist print them otherwise print:

No sequence found */


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

        bool found = false;

        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = i + 1; j < n; j++) {

                    if(arr[i] + arr[j] == arr[k]) {
                        cout << i << "," << j << "," << k << endl;
                        found = true;
                        break;
                    }
                }
                if(found) break;
            }
            if(found) break;
        }

        if(!found)
            cout << "No sequence found" << endl;
    }
}
