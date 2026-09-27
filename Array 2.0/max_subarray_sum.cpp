#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// Brute
// int maxSubarraySum(vector<int>& nums){
//     int maxsum = INT16_MIN;
//     for(int i = 0; i < nums.size(); i++){
//         int currsum = 0;
//         for(int j = i; j < nums.size(); j++){
//             currsum += nums[j];
//             maxsum = max(currsum, maxsum);
//         }
//     }
//     return maxsum;
// }

// int main(){
//     vector<int> nums = {2,-3,4,5,-1,5,6,-2};
//     cout<<"Maximum Subarray Sum: "<<maxSubarraySum(nums);
//     return 0;
// }

// Optimal: Kadane's algorithm
int maxSubarraySum(vector<int>& nums){
    int maxsum = INT16_MIN;
    int currsum = 0;
    for(int i = 0; i < nums.size(); i++){
        currsum += nums[i];
        maxsum = max(currsum, maxsum);
        if(currsum < 0){
            currsum = 0;
        }
    }
    return maxsum;
}

int main(){
    vector<int> nums = {2,-3,4,5,-1,5,6,-2};
    cout<<"Maximum Subarray Sum: "<<maxSubarraySum(nums);
    return 0;
}