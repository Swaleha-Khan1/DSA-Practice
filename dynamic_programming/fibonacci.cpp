#include<iostream>
#include<vector>
using namespace std;

// Memoization
int fibo(int n, vector<int>& dp){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];

    return dp[n] = fibo(n-1,dp)+fibo(n-2,dp);
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<fibo(n,dp);
    return 0;
}

// Tabulation
// int fibo(int n){
//     if(n<=1) return n;
//     vector<int> dp(n+1,-1);
//     dp[0] = 0;
//     dp[1] = 1;
//     for(int i = 2; i<=n; i++){
//         dp[i] = dp[i-1] + dp[i-2];
//     }

//     return dp[n];

// }

// int main(){
//     int n;
//     cout<<"Enter a number: ";
//     cin>>n;

//     cout<<fibo(n);
//     return 0;
// }

// Space Optimization
// int fibo(int n){
//     if(n<=1) return n;
//     int prev1 = 1;
//     int prev2 = 0;
//     for(int i = 2; i<=n; i++){
//         int curr = prev1 + prev2;
//         prev2 = prev1;
//         prev1 = curr;
//     }

//     return prev1;
// }

// int main(){
//     int n;
//     cout<<"Enter a number: ";
//     cin>>n;

//     cout<<fibo(n);
//     return 0;
// }

