/*
1️⃣ Question: Insertion Sort
Problem Statement

Given an unsorted array of integers, design an algorithm and implement a program to sort the array using Insertion Sort.
Also find:

total number of comparisons

total number of shifts
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
        int shifts = 0;

        for(int i = 1; i < n; i++) {

            int key = arr[i];
            int j = i - 1;

            while(j >= 0 && arr[j] > key) {
                comparisons++;
                arr[j+1] = arr[j];
                shifts++;
                j--;
            }

            if(j >= 0) comparisons++;

            arr[j+1] = key;
        }

        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;

        cout << "comparisons = " << comparisons << endl;
        cout << "shifts = " << shifts << endl;
    }
}
