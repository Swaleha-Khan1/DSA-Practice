#include<bits/stdc++.h>
using namespace std;

// int lengthOfLongestSubstring(string s){
//     int maxi = 0;
//     for(int i = 0; i<s.length(); i++){
//         unordered_map<char,int> mp;
//         for(int j = i; j<s.length(); j++){
//             if (mp[s[j]] == 1) break;

//             mp[s[j]]++;
//             maxi = max(maxi, j-i+1);
//         }
//     }
//     return maxi;
// }

// int main(){
//     string s = "abcabcbb";
//     cout<<lengthOfLongestSubstring(s);
//     return 0;
// }

// Optimal
int lengthOfLongestSubstring(string s){
    unordered_map<char,int> mpp;
    int r=0; int l=0;
    int n=s.length();
    int maxlen = 0;

    while(r < n){
        if(mpp.find(s[r]) != mpp.end()){
            if(mpp[s[r]] >= l){
                l = mpp[s[r]] + 1;
            }
        }
        int len = r - l + 1;
        maxlen = max(maxlen, len);

        mpp[s[r]]=r;   //storing indices
        r++;
    }
    return maxlen;
}

int main(){
    string s = "abcabcbb";
    cout<<lengthOfLongestSubstring(s);
    return 0;
}