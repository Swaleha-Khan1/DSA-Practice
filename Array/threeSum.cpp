#include <bits/stdc++.h>
using namespace std;

// Brute
int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    int n = nums.size();

    set<vector<int>> st;

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {

                if (nums[i] + nums[j] + nums[k] == 0) {

                    vector<int> temp = {
                        nums[i],
                        nums[j],
                        nums[k]
                    };

                    sort(temp.begin(), temp.end());

                    st.insert(temp);
                }
            }
        }
    }

    for (auto triplet : st) {
        cout << "[ ";
        for (int x : triplet) {
            cout << x << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}

// Better
// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>> triplet(int n, vector<int>& num)
// {
//     set<vector<int>> st;

//     for (int i = 0; i < n; i++)
//     {
//         set<int> hashset;

        // for (int j = i + 1; j < n; j++)
        // {
        //     int third = -(num[i] + num[j]);

        //     if (hashset.find(third) != hashset.end())
        //     {
        //         vector<int> temp = {num[i], num[j], third};

        //         sort(temp.begin(), temp.end());

        //         st.insert(temp);
//             }

//             hashset.insert(num[j]);
//         }
//     }

//     vector<vector<int>> ans(st.begin(), st.end());

//     return ans;
// }

// int main()
// {
//     vector<int> num = {-1, 0, 1, 2, -1, -4};

//     int n = num.size();

//     vector<vector<int>> ans = triplet(n, num);

//     for (auto triplet : ans)
//     {
//         cout << "[ ";

//         for (auto x : triplet)
//         {
//             cout << x << " ";
//         }

//         cout << "]" << endl;
//     }

//     return 0;
// }


// // Optimal
// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>> triplet(int n, vector<int>& num)
// {
//     vector<vector<int>> ans;

//     sort(num.begin(), num.end());

//     for (int i = 0; i < n; i++)
//     {

//         if (i > 0 && num[i] == num[i - 1])
//             continue;

//         int j = i + 1;
//         int k = n - 1;

//         while (j < k)
//         {
//             int sum = num[i] + num[j] + num[k];

//             if (sum < 0)
//             {
//                 j++;
//             }
//             else if (sum > 0)
//             {
//                 k--;
//             }
//             else
//             {
//                 vector<int> temp = {num[i], num[j], num[k]};

//                 ans.push_back(temp);

//                 j++;
//                 k--;

//                 while (j < k && num[j] == num[j - 1])
//                     j++;

//                 while (j < k && num[k] == num[k + 1])
//                     k--;
//             }
//         }
//     }

//     return ans;
// }

// int main()
// {
//     vector<int> num = {-1, 0, 1, 2, -1, -4};

//     int n = num.size();

//     vector<vector<int>> ans = triplet(n, num);

//     for (auto triplet : ans)
//     {
//         cout << "[ ";

//         for (auto x : triplet)
//         {
//             cout << x << " ";
//         }

//         cout << "]" << endl;
//     }

//     return 0;
// }