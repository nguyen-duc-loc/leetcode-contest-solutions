// Generated by LeetCodeContestHelper at 11/10/2024, 9:51:01 AM
// 100486. Sum of Good Subsequences
// https://leetcode.com/contest/weekly-contest-423/problems/sum-of-good-subsequences/

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

    int sumOfGoodSubsequences(vector<int>& nums) {
        int mx = ranges::max(nums);
        vector<long long> dp(mx + 5);
        vector<long long> cnt(mx + 5);
        for (auto& e : nums) {
            cnt[e]++;
            dp[e] += 1LL * e;
            cnt[e] %= mod;
            if (e > 0) {
                dp[e] +=
                    (dp[e - 1] + (1LL * (cnt[e - 1] % mod) * e) % mod) % mod;
                dp[e] %= mod;
                cnt[e] += cnt[e - 1];
                cnt[e] %= mod;
            }
            dp[e] += (dp[e + 1] + (1LL * (cnt[e + 1] % mod) * e) % mod) % mod;
            dp[e] %= mod;
            cnt[e] += cnt[e + 1];
            cnt[e] %= mod;
        }
        long long ans = 0;
        for (auto& e : dp) {
            ans += e % mod;
            ans %= mod;
        }
        return ans;
    }
};

// int Solution::sumOfGoodSubsequences(vector<int> nums)

int main() {
    cout << "*** 100486. Sum of Good Subsequences ***" << endl << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        vector<int> nums = {1, 2, 1};
        int ans0 = s0.sumOfGoodSubsequences(nums);
        int exp0 = 14;

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

        vector<int> nums = {3, 4, 5};
        int ans1 = s0.sumOfGoodSubsequences(nums);
        int exp1 = 40;

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