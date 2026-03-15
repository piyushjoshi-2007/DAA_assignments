/*
2️⃣ Question: Selection Sort
Problem Statement

Given an unsorted array, design an algorithm to sort the array using Selection Sort.
Also count:

number of comparisons

number of swaps

Time Complexity
O(n²)
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

        int comparisons = 0;
        int swaps = 0;

        for(int i = 0; i < n-1; i++) {

            int minIndex = i;

            for(int j = i+1; j < n; j++) {

                comparisons++;

                if(arr[j] < arr[minIndex])
                    minIndex = j;
            }

            if(minIndex != i) {
                swap(arr[i], arr[minIndex]);
                swaps++;
            }
        }

        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;

        cout << "comparisons = " << comparisons << endl;
        cout << "swaps = " << swaps << endl;
    }
}
