#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int upperBound(vector<int>& arr, int target){
    int n = arr.size();
    int start = 0;
    int end = n-1;
    int ans = n;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(arr[mid] > target){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,3,5,8,8,10,10,11};
    int target = 6;
    cout<<upperBound(arr, target);
    return 0;
}

// using stl
// int main(){

//     int arr[] = {1,2,3,3,5,8,8,10,10,11};
//     // vector<int> arr = {1,2,3,3,5,8,8,10,10,11};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int target = 9;

//     // int index = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
//     int index = upper_bound(arr, arr+n, target) - arr;
//     cout<<index;
//     return 0;
// }