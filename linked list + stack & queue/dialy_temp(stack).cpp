#include <bits/stdc++.h>
using namespace std;

vector<int> dialyTemperature(vector<int> &temp){
    int n = temp.size();
    vector<int> ans(n, 0);

    //stack to store indices
    stack<int> st;

    for(int i = 0; i<n; i++){

        //check if current temp is warmer
        while(!st.empty() && temp[i] > temp[st.top()]){
            //get the previous day's index
            int prev = st.top();
            st.pop();

            //calculate the number of days waited
            ans[prev] = i - prev;

        }
        st.push(i);
    }
    return ans;
}

int main(){
    vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = dialyTemperature(temp);

    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}