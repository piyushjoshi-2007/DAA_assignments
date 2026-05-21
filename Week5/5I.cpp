// Week5 - Ques(1) "Return the maximum occurrences number" 
#include<bits/stdc++.h>
using namespace std;

char getMaxDuplicateChar(char input[], int size) {

    int frequency[26] = {0};   // Stores frequency of each character

    // Step 1: Count frequency
    for (int i = 0; i < size; i++) {
        int index = input[i] - 'a';   // Map 'a' → 0, 'b' → 1 ...
        frequency[index]++;
    }

    int maxFrequency = 0;   // Highest frequency found
    int maxIndex = -1;      // Index of character with max frequency
    int maxCount = 0;       // Number of characters having max frequency

    // Step 2: Find maximum frequency and count how many have it
    for (int i = 0; i < 26; i++) {

        if (frequency[i] > maxFrequency) {
            maxFrequency = frequency[i];
            maxIndex = i;
            maxCount = 1;   // Reset count
        }
        else if (frequency[i] == maxFrequency && maxFrequency != 0) {
            maxCount++;     // Another character with same max frequency
        }
    }

    // Step 3: Handle edge cases

    // No duplicates
    if (maxFrequency <= 1) return '=';

    // Multiple characters share same max frequency
    if (maxCount > 1) return '!';

    // Unique character with highest frequency
    return (char)('a' + maxIndex);
}

int main(){
    int t;
    cout<<"Enter the test : ";
    cin>>t;
    while(t--){
        int n;
        cout<<"Enter the size of arr : ";
        cin>>n;
        vector<char>arr(n);
        for(int i = 0; i<n; i++ )
            cin>>arr[i];
        char ans = maxOccurenceElement(arr);
        if(ans == '?') cout<<"No Max 
        cout<<<<endl;
    }
}
