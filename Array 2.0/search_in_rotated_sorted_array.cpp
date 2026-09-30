#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int search(vector<int>& nums, int target){
    int n = nums.size();
    int left = 0; int right = n-1;

    while(left <= right){
        int mid = left + (right-left)/2;

        if(nums[mid] == target) return mid;

        if(nums[left] <= nums[mid]){
            if(nums[left] <= target && target <= nums[mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        else{
            if(nums[mid] <= target && target <= nums[right]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
    }
    return -1;

}

int main(){
    vector<int> nums = {7,8,9,1,2,3,4,5,6};
    int target = 1;
    cout<<search(nums, target);
    return 0;
}