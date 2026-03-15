/* 
3️⃣ Question 3: Count pairs with given difference
Problem Statement

Given an array of non-negative integers, design an algorithm to count number of pairs such that their difference is equal to a given key K.

Example

arr[i] - arr[j] = K

Output total number of such pairs.
*/

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
            for(int j = i + 1; j < n; j++) {

                if(abs(arr[i] - arr[j]) == key)
                    count++;
            }
        }

        cout << count << endl;
    }
}
