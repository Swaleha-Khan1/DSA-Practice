#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// Brute
// vector<int> productExceptSelf(vector<int>& nums){
//     int n = nums.size();
//     vector<int> ans(n, 1);
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             if(i!=j){
//                  ans[i] *= nums[i];
//             }
           
//         }
//     }
//     return ans;
// }

// int main(){
//     vector<int> nums = {2,3,1,5,7};
//     vector<int> ans = productExceptSelf(nums);
//     for(int x: ans){
//         cout<< x <<" ";
//     }
//     return 0;
// }

// Optimal
vector<int> productExceptSelf(vector<int>& nums){
    vector<int> ans(nums.size(),1);

    //prefix
    for(int i = 1; i < nums.size(); i++){
        ans[i] = ans[i-1]*nums[i-1];
    }
    //suffix
    int suffix = 1;
    for(int i = nums.size() - 1; i >= 0; i--){
        ans[i] *= suffix;
        suffix *= nums[i];
    }
    return ans;

}

int main(){
    vector<int> nums = {1,2,3,4};
    vector<int> ans = productExceptSelf(nums);
    for(int x: ans){
        cout<< x <<" ";
    }
    return 0;
}