#include <bits/stdc++.h>
using namespace std;

string encode(vector<string>& strs) {
    string ans = "";

    for (int i = 0; i < strs.size(); i++) {

        ans += to_string(strs[i].size()) + "#" + strs[i];

    }

    return ans;
}


vector<string> decode(string s) {

    vector<string> ans;

    int i = 0;

    while (i < s.size()) {

        int j = i;

        // Find the delimiter #
        while (s[j] != '#') {
            j++;
        }

        // Extract the length
        int len = stoi(s.substr(i, j - i));

        // Extract the actual string
        string word = s.substr(j + 1, len);

        ans.push_back(word);

        // Move i to the beginning of the next encoded string
        i = j + 1 + len;
    }

    return ans;
}


int main() {

    vector<string> strs = {"cat", "hello", "hi"};

    string encoded = encode(strs);

    cout << "Encoded: " << encoded << endl;

    vector<string> decoded = decode(encoded);

    cout << "Decoded: ";

    for (int i = 0; i < decoded.size(); i++) {
        cout << decoded[i] << " ";
    }

    return 0;
}