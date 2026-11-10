#include <bits/stdc++.h>
using namespace std;

// Brute force
// bool isPalindrome(string s){
//     int i = 0;
//     int j = s.size() -1;
//     while(i < j){
//         if(s[i] != s[j]){
//             return false;
//         }
//         i++;
//         j--;
//     }
//     return true;
// }
// string longestPalindromicString(string s){
//     string ans = "";
//     for(int i = 0; i < s.size(); i++){
//         for(int j = i; j < s.size(); j++){
//             string sub = s.substr(i, j-i+1);
//             if(isPalindrome(sub)){
//                 if(sub.size() > ans.size()){
//                     ans = sub;
//                 }
//             }
//         }
//     }
//     return ans;
// }
// int main(){
//     string s = "babad";
//     cout<<longestPalindromicString(s);
//     return 0;
// }

// Optimal
#include <bits/stdc++.h>
using namespace std;

bool f(int i, int j, string &s, vector<vector<int>>& dp) {
    // Base case
    if (i >= j)
        return true;

    // Check if already calculated
    if (dp[i][j] != -1) return dp[i][j];

    // If characters don't match
    if (s[i] != s[j]) {
        dp[i][j] = 0;
        return false;
    }
    // If characters match
    return dp[i][j] = f(i+1, j-1, s, dp);
}
string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int start = 0;
    int maxLen = 1;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            if (f(i, j, s, dp)) {

                if (j-i+1 > maxLen) {
                    start = i;
                    maxLen = j-i+1;
                }

            }
        }
    }
    return s.substr(start, maxLen);
}
int main() {
    string s = "babad";
    cout << longestPalindrome(s);
    return 0;
}