#include <bits/stdc++.h>
using namespace std;

// Brute
int trap(vector<int>& height){
    int n = height.size();

    vector<int> leftmax(n);
    vector<int> rightmax(n);

    //prefixmax
    leftmax[0] = height[0];
    for(int i = 1; i < n ; i++){
        leftmax[i] = max(leftmax[i-1], height[i]);
    }

    //suffixmax
    rightmax[n-1] = height[n-1];
    for(int i = n-2; i >= 0 ; i--){
        rightmax[i] = max(rightmax[i+1], height[i]);
    }

    int water = 0;
    for(int i = 0; i < n ; i++){
        water += min(leftmax[i], rightmax[i]) - height[i];
    }
    return water;
}

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(height);
    return 0;
}

// Optimal : two pointer

// #include <bits/stdc++.h>
// using namespace std;

// int trap(vector<int>& height){
//     int left = 0;
//     int right = height.size() - 1;

//     int leftmax = 0;
//     int rightmax = 0;
//     int water = 0;

//     while(left <= right){
//         if(height[left] <= height[right]){
//             if(height[left] >= leftmax){
//                 leftmax = height[left];
//             }
//             else{
//                 water += leftmax - height[left];
//             }
//             left++;
//         }
//         else{
//             if(height[right] >= rightmax){
//                 rightmax = height[right];
//             }
//             else{
//                 water += rightmax - height[right];
//             }
//             right--;
//         }
//     }
//     return water;
// }


// int main(){
//     vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
//     cout<<trap(height);
//     return 0;
// }