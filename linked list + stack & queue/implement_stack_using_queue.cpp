#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> q;

public:
    MyStack() {
    }

    void push(int x) {
        q.push(x);

        int n = q.size();

        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        int ans = q.front();
        q.pop();
        return ans;
    }

    int top() {
        if (q.empty()) {
            return -1;
        }

        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl;

    cout << "Removed: " << s.pop() << endl;
    cout << "Top: " << s.top() << endl;

    cout << "Removed: " << s.pop() << endl;

    cout << "Is empty: " << s.empty() << endl;

    return 0;
}