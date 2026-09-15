#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int binarySearch(vector<int>& arr, int target){
    int start = 0;
    int end = arr.size() - 1;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(target < arr[mid]){
            end = mid - 1;
        }
        else if(target > arr[mid]){
            start = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {-2,4,5,15,34,57,60,81,90};
    int target = 5;
    cout<<binarySearch(arr, target);
    return 0;
}

// int orderAgnosticBinarySearch(vector<int>& arr, int target){
//     int start = 0;
//     int end = arr.size() - 1;
//     bool isAsc;
//     if(arr[start] < arr[end]){
//         isAsc = true;
//     }
//     else{
//         isAsc = false;
//     }

//     while(start <= end){
//         int mid = start + (end-start)/2;

//         if(arr[mid] == target){
//             return mid;
//         }

//         if(isAsc){
//             if(target < arr[mid]){
//                 end = mid - 1;
//             }
//             else{
//                 start = mid + 1;
//             }
//         }
//         else{
//             if(target > arr[mid]){
//                 end = mid - 1;
//             }
//             else{
//                 start = mid + 1;
//             }
//         }
//     }
//     return -1;
// }

// int main(){
//     vector<int> arr = {90,80,66,45,44,32,20,1,-4};
//     int target = 20;
//     cout<<orderAgnosticBinarySearch(arr, target);
//     return 0;
// }