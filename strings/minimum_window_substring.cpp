#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    int n = s.size();
    int m = t.size();

    vector<int> hash(256, 0);

    //stror all the t characters in hashmap

    for(int i = 0; i < m; i++)
    {
        hash[t[i]]++;
    }

    int l = 0, r = 0;
    int minLen = INT_MAX;
    int sIndex = -1;       //strating index of the obtained window
    int cnt = 0;           //counts the characters found in s that are in t

    while(r < n)
    {
        if(hash[s[r]] > 0)    //if char frequency is +ve that means it is prestored (appears in t) we increse cnt
            cnt++;

        hash[s[r]]--;        //decrease the frequecy 

        //shrink the window
        while(cnt == m)     
        {
            if(r - l + 1 < minLen)
            {
                minLen = r - l + 1;
                sIndex = l;
            }

            //remove the left char
            hash[s[l]]++;      //add a frequency in hashmap

            if(hash[s[l]] > 0)
                cnt--;

            l++;
        }

        r++;
    }

    if(sIndex == -1)
        return "";

    return s.substr(sIndex, minLen);
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << minWindow(s, t);

    return 0;
}