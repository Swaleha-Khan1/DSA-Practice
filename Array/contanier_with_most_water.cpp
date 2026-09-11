#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Brute 
int maxArea(vector<int>& height){
    int max_water = 0;
    int n = height.size();

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int width = j-i;
            int h = min(height[i], height[j]);

            int curr_area = width*h;

            max_water = max(curr_area, max_water);
        }
    }
    return max_water;
}

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<<"Max Water: "<<maxArea(height)<<endl;
    return 0;
}


// Optimal
// int maxArea(vector<int>& height) {
//    int ans = 0;
//     int n = height.size();
//     int lp = 0;
//     int rp = n-1;
//     while(lp<rp){
//         int w = rp-lp;
//         int h = min(height[lp], height[rp]);
//         int curr_max = w*h;

//         ans = max(ans, curr_max);

//         height[lp]<height[rp]? lp++ : rp--;
//     }

//     return ans;
// }

// int main(){
//     vector<int> height = {1,8,6,2,5,4,8,3,7};
//     cout<<"Max Water: "<<maxArea(height)<<endl;
//     return 0;
// }