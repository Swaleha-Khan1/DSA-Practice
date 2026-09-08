#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

//Brute
vector<int> twoSum(vector<int>& nums, int target) {

    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]+nums[j]==target){
                return {i,j};
            }
        }
    }
    return {};
}

int main(){
    vector<int> nums;
    int target = 14;
    nums = {2,6,5,8,11};
    vector<int> result=twoSum(nums,target);
    if(!result.empty()){
        cout<<"Indices: "<<result[0]<<","<<result[1];
    } else {
        cout<<"No pair found";
    }
    return 0;
}

// Better
// vector<int> twoSum(vector<int>& nums,int target){
//     unordered_map<int,int> mpp;
//     for(int i=0;i<nums.size();i++){
//         int complement = target - nums[i];

//         if(mpp.find(complement) != mpp.end()){
//             return {mpp[complement], i};
//         }
//         mpp[nums[i]] = i;
//     }
//     return {};
// }

// int main(){
//     vector<int> nums = {2,7,11,15};
//     int target = 9;
//     vector<int> ans = twoSum(nums, target);
//     cout<<ans[0]<<" "<<ans[1];

//     return 0;
// }

// Optimal
// bool twoSum(vector<int>& nums, int target){
//     sort(nums.begin(), nums.end());

//     int left = 0;
//     int right = nums.size() - 1;

//     while(left < right){
//         int sum = nums[left] + nums[right];

//         if(sum == target){
//             return true;
//         }
//         else if(sum<target) left++;
//         else right--;
//     }
//     return false;
// }

// int main(){
//     vector<int> nums = {2,7,11,15};
//     int target = 9;
//     if(twoSum(nums, target)){
//         cout<<"Yes";
//     }
//     else cout<<"No";

//     return 0;
// }