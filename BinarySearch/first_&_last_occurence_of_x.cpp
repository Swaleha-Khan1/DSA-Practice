#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4};
    int target = 2;

    int n = arr.size();

    int first = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    int last = upper_bound(arr.begin(), arr.end(), target) - arr.begin() - 1;

    // Check if target exists
    if (first == n || arr[first] != target) {
        cout << -1 << " " << -1;
    }
    else {
        cout << first << " " << last;
    }

    return 0;
}