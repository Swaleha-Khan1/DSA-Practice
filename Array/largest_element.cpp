#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int largest(vector<int> &arr, int n){
    int largest=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    return largest;
}

int main(){
    vector<int> arr={12,43,54,23,36};
    int n = arr.size();
    cout<<largest(arr,n);
    
    return 0;
}