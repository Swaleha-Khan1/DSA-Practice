#include<bits/stdc++.h>
using namespace std;

// vector<vector<string>> groupAnagrams(vector<string>& strs){
//     unordered_map<string, vector<string>> mpp;    //key: sorted string, value: strings that sort to that key
//     for(int i = 0; i < strs.size(); i++){
//         string s = strs[i];
//         sort(s.begin(), s.end());
//         mpp[s].push_back(strs[i]);  //pushes eat into the vector associated with aet...strs[i]=eat and mp[s]=aet
//     }
//     vector<vector<string>> ans;
//     for(auto it : mpp){
//         ans.push_back(it.second);
//     }
//     return ans;
// }

// int main(){
//     vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
//     vector<vector<string>> ans = groupAnagrams(strs);
//     for(auto v : ans){             //goes through each group
//         for(auto s : v){           //goes through each string in that group
//             cout << s << " ";
//         }
//         cout << endl;              //moves to the next line after each group
//     }
//     return 0;
// }

// Optimal
vector<vector<string>> groupAnagrams(vector<string>& strs){
    map<vector<int>, vector<string>> mpp;
    for(int i = 0; i < strs.size(); i++){
        vector<int> freq(26,0);
        for(int j = 0; j < strs[i].length(); j++){
            freq[strs[i][j] - 'a']++;
        }
        mpp[freq].push_back(strs[i]);
    }
    vector<vector<string>> ans;
    for(auto it : mpp){
        ans.push_back(it.second);
    }
    return ans;
}

int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = groupAnagrams(strs);
    for(auto v : ans){             //goes through each group
        for(auto s : v){           //goes through each string in that group
            cout << s << " ";
        }
        cout << endl;              //moves to the next line after each group
    }
    return 0;
}