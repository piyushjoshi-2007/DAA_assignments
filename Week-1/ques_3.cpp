/* Question 3: Jump Search

Problem Statement:
Given an already sorted array of positive integers, 
design an algorithm and implement it using a program to find whether the given key element is present in the array or not using Jump Search technique.
The algorithm first checks elements at indexes
arr[0], arr[2], arr[4], …, arr[2k] and once the interval containing the key is found, perform linear search within that block.

Time Complexity:
O(√n) */



#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {

        int n;
        cin >> n;

        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin >> arr[i];

        int key;
        cin >> key;

        int step = sqrt(n);
        int prev = 0;
        int comparisons = 0;
        bool found = false;

        while(arr[min(step,n)-1] < key) {
            comparisons++;
            prev = step;
            step += sqrt(n);

            if(prev >= n) {
                cout<<"Not Present "<<comparisons<<endl;
                found = true;
                break;
            }
        }

        if(!found){
            for(int i=prev;i<min(step,n);i++){
                comparisons++;
                if(arr[i]==key){
                    cout<<"Present "<<comparisons<<endl;
                    found = true;
                    break;
                }
            }

            if(!found)
                cout<<"Not Present "<<comparisons<<endl;
        }
    }
}
