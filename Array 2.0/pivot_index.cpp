#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int pivotIndex(vector<int>& nums){
    int total = 0;
    for(int x : nums){
        total += x;
    }
    int leftsum = 0;
    for(int i=0; i<nums.size(); i++){
        int rightsum = total - leftsum - nums[i];
        if(leftsum == rightsum){
            return i;
        }
        leftsum += nums[i];
    }
    return -1;
}

int main(){
    vector<int> nums = {1,7,3,6,5,6};
    cout<<pivotIndex(nums);
    return 0;
}