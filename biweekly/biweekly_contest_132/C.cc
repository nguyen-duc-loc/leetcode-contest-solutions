// Generated by LeetCodeContestHelper at 6/8/2024, 9:44:51 PM
// 100331. Find the Maximum Length of a Good Subsequence I
// https://leetcode.com/contest/biweekly-contest-132/problems/find-the-maximum-length-of-a-good-subsequence-i/

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
    int maximumLength(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<vector<int>> dp(n, vector<int>(k + 2, INT_MIN));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
            for (int j = 0; j < i; j++) {
                for (int l = 0; l <= k; l++) {
                    if (dp[j][l] != INT_MIN) {
                        dp[i][l + (nums[i] != nums[j])] =
                            max(dp[i][l + (nums[i] != nums[j])], dp[j][l] + 1);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

// int Solution::maximumLength(vector<int> nums, int k)

int main() {
    cout << "*** 100331. Find the Maximum Length of a Good Subsequence I ***"
         << endl
         << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        vector<int> nums = {1, 2, 1, 1, 3};
        int k = 2;
        int ans0 = s0.maximumLength(nums, k);
        int exp0 = 4;

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

        vector<int> nums = {1, 2, 3, 4, 5, 1};
        int k = 0;
        int ans1 = s0.maximumLength(nums, k);
        int exp1 = 2;

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
