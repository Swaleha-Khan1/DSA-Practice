#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


// Brute
// void rotate(int arr[], int n, int k){
//     k = k%n;

//     int temp[k];
//     for(int i=0;i<k;i++){
//         temp[i] = arr[i];
//     }

//     for(int i=k;i<n;i++){
//         arr[i-k] = arr[i];
//     }

//     for(int i=n-k;i<n;i++){
//         arr[i] = temp[i-(n-k)];
//     }

// }

// int main(){
    
//     int arr[] = {1,2,3,4,5,6,7,8};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int k = 3;
//     rotate(arr,n,k);

//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }

//     return 0;
// }

// Optimal
void rotate(int arr[], int n, int k){
    k = k%n;
    reverse(arr,arr+k);
    reverse(arr+k,arr+n);
    reverse(arr,arr+n);
}

int main(){
    
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    rotate(arr,n,k);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}