#include <bits/stdc++.h>

using namespace std;

bool isValid(string str) {
    stack<char> st;

    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
            st.push(str[i]);
        }
        else {
            if(st.size() == 0) {
                return false;
            }

            if((st.top() == '(' && str[i] == ')') ||
               (st.top() == '{' && str[i] == '}') ||
               (st.top() == '[' && str[i] == ']')) {
                st.pop();
            }
            else {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {
    string str;
    cout << "Enter brackets: ";
    cin >> str;

    if(isValid(str)) {
        cout << "Valid";
    }
    else {
        cout << "Invalid";
    }

    return 0;
}

