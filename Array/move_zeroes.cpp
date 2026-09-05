#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Brute
// vector<int> f(vector<int>& arr, int n){
//     //step 1
//     vector<int> temp;
//     for(int i=0;i<n;i++){
//         if(arr[i]!=0){
//             temp.push_back(arr[i]);
//         }
//     }

//     //step 2
//     for(int i=0;i<temp.size();i++){
//         arr[i]=temp[i];
//     }

//     //step 3
//     for(int i=temp.size();i<n;i++){
//         arr[i]=0;
//     }
//     return arr;
// }
// int main(){
//     vector<int> arr;
//     arr = {1,2,0,4,5,0,0,7,6};
//     int n = arr.size();
//     f(arr,n);

//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }

//Optimal
vector<int> f(vector<int>& arr, int n){
    int j = -1;
    // find first zero
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j = i;
            break;
        }
    }
    // non zero numbers
    if(j == -1) return arr;

    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    return arr;
}

int main(){
    vector<int> arr;
    arr = {1,2,0,4,5,0,0,7,6};
    int n = arr.size();
    f(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}