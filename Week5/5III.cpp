#include<bits/stdc++.h>
using namespace std;

void commonElement(vector<int>A, vector<int>B){
    int n1 = A.size();
    int n2 = B.size();
    int i = 0;
    int j = 0;
    while(i<n1 && j<n2){
        if(A[i]==B[j])
            {cout<<A[i]<<endl;
                i++;
                j++;
        }
        else if(A[i]<B[j]) i++;
        else j++;
    }
}

int main(){
    int n;
    cout<<"Enter the trials : ";
    cin>>n;
    while(n--){
        int n1, n2;
        cout<<"Enter the size of Array A : ";
        cin>>n1;
        vector<int>A(n1);
        for(int i = 0; i<n1; i++)
            cin>>A[i];
        cout<<"Enter the size of Array B : ";
        cin>>n2;
        vector<int>B(n2);
        for(int j = 0; j<n2; j++)
            cin>>B[j];

        cout<<"The common elements are : ";
        commonElement(A, B);
    }
}