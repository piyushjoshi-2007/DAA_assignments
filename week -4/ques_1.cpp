/*
1️⃣ Question: Merge Sort (comparisons + inversions)
Problem Statement

Given an unsorted array of integers, design an algorithm to sort the array using Merge Sort.
Also count:

number of comparisons

number of inversions

(Inversion: jab arr[i] > arr[j] ho aur i < j ho)
*/

#include <iostream>
#include <vector>
using namespace std;

int comparisons = 0;
int inversions = 0;

void merge(vector<int>& arr,int l,int m,int r){

    int n1 = m-l+1;
    int n2 = r-m;

    vector<int> L(n1),R(n2);

    for(int i=0;i<n1;i++)
        L[i]=arr[l+i];

    for(int j=0;j<n2;j++)
        R[j]=arr[m+1+j];

    int i=0,j=0,k=l;

    while(i<n1 && j<n2){
        comparisons++;

        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else{
            arr[k++] = R[j++];
            inversions += (n1-i);
        }
    }

    while(i<n1)
        arr[k++] = L[i++];

    while(j<n2)
        arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr,int l,int r){
    if(l<r){

        int m=(l+r)/2;

        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);

        merge(arr,l,m,r);
    }
}

int main(){

    int T;
    cin>>T;

    while(T--){

        int n;
        cin>>n;

        vector<int> arr(n);

        for(int i=0;i<n;i++)
            cin>>arr[i];

        comparisons = 0;
        inversions = 0;

        mergeSort(arr,0,n-1);

        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;

        cout<<"comparisons = "<<comparisons<<endl;
        cout<<"inversions = "<<inversions<<endl;
    }
}
