#include<iostream>
#include<unordered_map>
using namespace std;

// Brute
// bool isAnagram(string s, string t){
//     if(s.length() != t.length()){
//         return false;
//     }
//     unordered_map<char, int> mp;
//     for(int i=0; i<s.length(); i++){
//         mp[s[i]]++;
//         mp[t[i]]--;
//     }
//     for(auto it:mp){
//         if(it.second != 0){
//             return false;
//         }
//     }
//     return true;
// }
// int main(){
//     string s = "anagram";
//     string t = "nagaram";

//     cout<<(isAnagram(s,t) ? "true" : "false");  //isAnagram(s,t) will return 1 and 0
//     return 0;
// }

// Optimal
bool isAnagram(string s, string t){
    if(s.length() != t.length()){
        return false;
    }
    int freq[26] = {0};
    for(int i=0; i<s.length(); i++){
        freq[s[i] - 'a']++;
        freq[s[i] - 'a']--;
    }
    for(int i=0; i<26; i++){
        if(freq[i] != 0){
            return false;
        }
    }
    return true;
}
int main(){
    string s = "anagram";
    string t = "nagaram";

    cout<<(isAnagram(s,t) ? "true" : "false");  //isAnagram(s,t) will return 1 and 0
    return 0;
}