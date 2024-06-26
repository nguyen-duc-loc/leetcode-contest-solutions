// Generated by LeetCodeContestHelper at 4/30/2024, 3:05:06 AM
// 3043. Find the Length of the Longest Common Prefix
// https://leetcode.com/contest/weekly-contest-385/problems/find-the-length-of-the-longest-common-prefix/

#define _USE_MATH_DEFINES
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <forward_list>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st;
        for (auto& e : arr1) {
            string s = to_string(e);
            for (int i = 1; i <= (int)s.size(); i++) {
                st.insert(s.substr(0, i));
            }
        }
        int ans = 0;
        for (auto& e : arr2) {
            string s = to_string(e);
            for (int i = 1; i <= (int)s.size(); i++) {
                if (st.count(s.substr(0, i))) {
                    ans = max(ans, i);
                }
            }
        }
        return ans;
    }
};

// int Solution::longestCommonPrefix(vector<int> arr1, vector<int> arr2)

int main() {
    cout << "*** 3043. Find the Length of the Longest Common Prefix ***" << endl
         << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        vector<int> arr1 = {1, 10, 100};
        vector<int> arr2 = {1000};
        int ans0 = s0.longestCommonPrefix(arr1, arr2);
        int exp0 = 3;

        if (ans0 == exp0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
            cout << "  Answer: " << ans0 << endl;
            cout << "  Expect: " << exp0 << endl;
        }
    }

    {
        cout << "Test 2: ";

        vector<int> arr1 = {1, 2, 3};
        vector<int> arr2 = {4, 4, 4};
        int ans1 = s0.longestCommonPrefix(arr1, arr2);
        int exp1 = 0;

        if (ans1 == exp1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
            cout << "  Answer: " << ans1 << endl;
            cout << "  Expect: " << exp1 << endl;
        }
    }

    return 0;
}
