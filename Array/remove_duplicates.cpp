#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int uniqueelements(vector<int>& arr, int n){
    int i = 0;
    for(int j=1;j<n;j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}
int main(){
    vector<int> arr={1,1,2,2,3,3};
    int n = arr.size();
    cout<<uniqueelements(arr, n);
    
    return 0;
}