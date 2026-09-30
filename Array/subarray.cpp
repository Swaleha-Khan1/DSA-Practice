#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(){
    vector<int> nums = {1,2,3,4,5};
    for(int i=0;i<nums.size();i++){
        for(int j=i;j<nums.size();j++){
            for(int k=i;k<=j;k++){
                cout<<nums[k];
            }
            cout<<" ";
        }
        cout<<endl;
    }
}