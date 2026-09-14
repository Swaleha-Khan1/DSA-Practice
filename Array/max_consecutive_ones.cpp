#include <bits/stdc++.h>
using namespace std;

// Brute
int longestOnes(vector<int>& nums, int k){
    int n = nums.size();
    int maxi = 0;

    for(int i=0; i<n; i++){
        int zeros = 0;
        for(int j=i; j<n; j++){
            if(nums[j]==0){
                zeros++;
            }
            if(zeros<=k){
                int len = j-i+1;
                maxi = max(maxi, len);
            }
        }
    }
    return maxi;
}
int main(){
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout<<longestOnes(nums, k);

    return 0;
}


// // Optimal
// #include <bits/stdc++.h>
// using namespace std;

// int longestOnes(vector<int>& nums, int k){
//     int left = 0;
//     int zeros = 0;
//     int maxi = 0;
//     for(int right = 0; right<nums.size(); right++){
//         if(nums[right] == 0){
//             zeros++;
//         }

//         while(zeros > k){
//             if(nums[left] == 0){
//                 zeros--;
//             }
//             left++;
//         }
//         maxi = max(maxi, right - left + 1);
//     }
//     return maxi;
// }

// int main(){
//     vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
//     int k = 2;
//     cout<<longestOnes(nums, k);

//     return 0;
// }