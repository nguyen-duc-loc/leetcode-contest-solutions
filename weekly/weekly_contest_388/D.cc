// Generated by LeetCodeContestHelper at 4/30/2024, 3:22:46 AM
// 3077. Maximum Strength of K Disjoint Subarrays
// https://leetcode.com/contest/weekly-contest-388/problems/maximum-strength-of-k-disjoint-subarrays/

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
    long long maximumStrength(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<vector<vector<long long>>> dp(
            n + 1,
            vector<vector<long long>>(k + 1, vector<long long>(2, LLONG_MIN)));
        dp[0][0][1] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                long long sign = (j % 2 == 0 ? -1 : 1);
                long long val = 1LL * nums[i - 1] * (k - j + 1);
                if (dp[i - 1][j][0] != LLONG_MIN)
                    dp[i][j][0] =
                        max(dp[i][j][0], dp[i - 1][j][0] + sign * val);
                if (j >= 1 && dp[i - 1][j - 1][1] != LLONG_MIN)
                    dp[i][j][0] =
                        max(dp[i][j][0], dp[i - 1][j - 1][1] + sign * val);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i][j][0]);
            }
        }
        long long ans = LLONG_MIN;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, dp[i][k][1]);
        }
        return ans;
    }
};

// long long Solution::maximumStrength(vector<int> nums, int k)

int main() {
    cout << "*** 3077. Maximum Strength of K Disjoint Subarrays ***" << endl
         << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        vector<int> nums = {1, 2, 3, -1, 2};
        int k = 3;
        long long ans0 = s0.maximumStrength(nums, k);
        long long exp0 = 22;

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

        vector<int> nums = {12, -2, -2, -2, -2};
        int k = 5;
        long long ans1 = s0.maximumStrength(nums, k);
        long long exp1 = 64;

        if (ans1 == exp1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
            cout << "  Answer: " << ans1 << endl;
            cout << "  Expect: " << exp1 << endl;
        }
    }

    {
        cout << "Test 3: ";

        vector<int> nums = {-1, -2, -3};
        int k = 1;
        long long ans2 = s0.maximumStrength(nums, k);
        long long exp2 = -1;

        if (ans2 == exp2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
            cout << "  Answer: " << ans2 << endl;
            cout << "  Expect: " << exp2 << endl;
        }
    }

    return 0;
}
