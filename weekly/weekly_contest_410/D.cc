// Generated by LeetCodeContestHelper at 8/11/2024, 10:06:12 AM
// 100396. Find the Count of Monotonic Pairs II
// https://leetcode.com/contest/weekly-contest-410/problems/find-the-count-of-monotonic-pairs-ii/

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
    const long long mod = (long long)1e9 + 7;

    int countOfPairs(vector<int>& nums) {
        int n = (int)nums.size();
        vector<vector<int>> dp(n, vector<int>(1001));
        for (int i = 0; i <= nums[0]; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int k = 1; k <= 1000; k++) {
                dp[i - 1][k] += dp[i - 1][k - 1];
                dp[i - 1][k] %= mod;
            }
            for (int k = 0; k <= nums[i]; k++) {
                if (nums[i - 1] - nums[i] + k >= 0) {
                    dp[i][k] += dp[i - 1][min(nums[i - 1] - nums[i] + k, k)];
                    dp[i][k] %= mod;
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i <= nums[n - 1]; i++) {
            ans += dp[n - 1][i];
            ans %= mod;
        }
        return ans;
    }
};

// int Solution::countOfPairs(vector<int> nums)

int main() {
    cout << "*** 100396. Find the Count of Monotonic Pairs II ***" << endl
         << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        vector<int> nums = {2, 3, 2};
        int ans0 = s0.countOfPairs(nums);
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

        vector<int> nums = {5, 5, 5, 5};
        int ans1 = s0.countOfPairs(nums);
        int exp1 = 126;

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