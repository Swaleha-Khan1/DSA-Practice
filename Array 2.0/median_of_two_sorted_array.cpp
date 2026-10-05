#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// Brute 
// double findMedianSortedArray(vector<int>& nums1, vector<int>& nums2){
//     vector<int> arr;
//     int i = 0;
//     int j = 0;

//     while(i < nums1.size() && j < nums2.size()){
//         if(nums1[i] < nums2[j]){
//             arr.push_back(nums1[i]);
//             i++;
//         }
//         arr.push_back(nums2[j]);
//         j++;
//     }
//     while(i < nums1.size()){
//         arr.push_back(nums1[i]);
//         i++;
//     }
//     while(j < nums2.size()){
//         arr.push_back(nums2[j]);
//         j++;
//     }

//     int n = arr.size();
//     if(n % 2 == 1){
//         return arr[n/2];
//     }
//     else{
//         return (arr[n/2] + arr[n/2 - 1]) / 2.0;
//     }
// }

// int main(){
//     vector<int> nums1 = {1,3,4,7,10,12};
//     vector<int> nums2 = {2,3,6,15};
//     cout<<findMedianSortedArray(nums1, nums2);
//     return 0;
// }

// Better
// double findMedianSortedArray(vector<int>& nums1, vector<int>& nums2){
//     int i = 0;
//     int j = 0;
//     int n1 = nums1.size(); int n2 = nums2.size();
//     int count = 0;
//     int n = (n1+n2);
//     int ind2 = n/2;
//     int ind1 = ind2 - 1;
//     int indel1 = -1; int indel2 = -1;

//     while(i < n1 && j < n2){
//         if(nums1[i] < nums2[j]){
//             if(count == ind1) indel1 = nums1[i];
//             if(count == ind2) indel2 = nums1[i];
//             count++;
//             i++;
//         }
//         else{
//             if(count == ind1) indel1 = nums2[j];
//             if(count == ind2) indel2 = nums2[j];
//             count++;
//             j++;
//         }
//     }
//     while(i < n1){
//         if(count == ind1) indel1 = nums1[i];
//         if(count == ind2) indel2 = nums1[i];
//         count++;
//         i++;
//     }
//     while(j < n2){
//         if(count == ind1) indel1 = nums2[j];
//         if(count == ind2) indel2 = nums2[j];
//         count++;
//         j++;
//     }
//     if(n%2==1){
//         return indel2;
//     }
    
//     return (indel1 + indel2) / 2.0;
// }

// int main(){
//     vector<int> nums1 = {1,3,4,7,10,12};
//     vector<int> nums2 = {2,3,6,15};
//     cout<<findMedianSortedArray(nums1, nums2);
//     return 0;
// }

// Optimal

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    // Make nums1 the smaller array
    if(nums1.size() > nums2.size()) {
        swap(nums1, nums2);
    }

    int n1 = nums1.size();
    int n2 = nums2.size();

    int low = 0;
    int high = n1;

    // Number of elements that should be on the left side
    int totalLeft = (n1 + n2 + 1) / 2;

    while(low <= high) {

        // Partition of nums1
        int partition1 = (low + high) / 2;

        // Remaining elements needed from nums2
        int partition2 = totalLeft - partition1;

        // Elements just before and after partition1
        int left1;
        int right1;

        if(partition1 == 0)
            left1 = INT_MIN;
        else
            left1 = nums1[partition1 - 1];

        if(partition1 == n1)
            right1 = INT_MAX;
        else
            right1 = nums1[partition1];


        // Elements just before and after partition2
        int left2;
        int right2;

        if(partition2 == 0)
            left2 = INT_MIN;
        else
            left2 = nums2[partition2 - 1];

        if(partition2 == n2)
            right2 = INT_MAX;
        else
            right2 = nums2[partition2];


        // Correct partition
        if(left1 <= right2 && left2 <= right1) {

            // Total number of elements is odd
            if((n1 + n2) % 2 == 1) {
                return max(left1, left2);
            }

            // Total number of elements is even
            return (max(left1, left2) + min(right1, right2)) / 2.0;
        }

        // We have taken too many elements from nums1
        else if(left1 > right2) {
            high = partition1 - 1;
        }

        // We need to take more elements from nums1
        else {
            low = partition1 + 1;
        }
    }

    return 0.0;
}


int main() {

    vector<int> nums1 = {1, 3, 5};
    vector<int> nums2 = {2, 4, 6};

    cout << findMedianSortedArrays(nums1, nums2);

    return 0;
}