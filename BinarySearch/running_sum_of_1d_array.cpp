#include<iostream>
#include<bits/stdc++.h>

using namespace std;
vector<int> runningSum(vector<int>& arr){
    for(int i = 1; i < arr.size(); i++){
        arr[i] += arr[i-1];
    }
    return arr;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    runningSum(arr);

    cout<<"Running Sum: ";
    for(int x : arr){
        cout<<x<<" ";
    }
    return 0;
}