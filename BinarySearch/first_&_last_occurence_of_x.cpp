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

// Using simple binary search
// #include <iostream>
// #include <vector>
// using namespace std;

// int firstOccurrence(vector<int>& arr, int n, int k)
// {
//     int low = 0, high = n - 1;
//     int first = -1;

//     while (low <= high)
//     {
//         int mid = (low + high) / 2;

//         if (arr[mid] == k)
//         {
//             first = mid;
//             high = mid - 1;
//         }
//         else if (arr[mid] < k)
//         {
//             low = mid + 1;
//         }
//         else
//         {
//             high = mid - 1;
//         }
//     }

//     return first;
// }

// int lastOccurrence(vector<int>& arr, int n, int k)
// {
//     int low = 0, high = n - 1;
//     int last = -1;

//     while (low <= high)
//     {
//         int mid = (low + high) / 2;

//         if (arr[mid] == k)
//         {
//             last = mid;
//             low = mid + 1;
//         }
//         else if (arr[mid] < k)
//         {
//             low = mid + 1;
//         }
//         else
//         {
//             high = mid - 1;
//         }
//     }

//     return last;
// }

// int main()
// {
//     vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    
//     int n = arr.size();
//     int k = 2;

//     int first = firstOccurrence(arr, n, k);
//     int last = lastOccurrence(arr, n, k);

//     cout << "First occurrence: " << first << endl;
//     cout << "Last occurrence: " << last << endl;

//     return 0;
// }