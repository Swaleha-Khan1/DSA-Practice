#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Brute
// int subarraySum(vector<int>& nums, int k){
//     int n = nums.size();
//     int count = 0;

//     for(int i=0; i<n; i++){
//         int sum = 0;
//         for(int j=i; j<n; j++){
//             sum += nums[j];
//             if(sum == k) count++;
//         }
//     }
//     return count;
// }
// int main(){
//     vector<int> nums = {1,2,3};
//     int k = 3;
//     cout<<subarraySum(nums,k);
//     return 0;
// }


// Optimal
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> mpp;
    mpp[0]=1;
    int presum = 0; int count = 0;
    for(int i=0;i<nums.size();i++){
        presum+=nums[i];
        int remove = presum - k;
        count+=mpp[remove];
        mpp[presum]+=1;
    }
        return count;
}

int main(){
    vector<int> nums = {1,2,3};
    int k = 3;
    cout<<subarraySum(nums,k);
    return 0;
}