#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int seclargest(vector<int>& arr, int n){
    int largest = arr[0];
    int secondlargest = -1;

    for(int i = 0; i < n; i++){
        if(arr[i]>largest){
            secondlargest = largest;
            largest = arr[i];
        }
        else if(arr[i]<largest && arr[i]>secondlargest){
            secondlargest = arr[i];
        }
    }
    return secondlargest;
}

int main(){
    vector<int> arr={12,43,54,23,36};
    int n = arr.size();
    cout<<seclargest(arr,n);
    
    return 0;
}