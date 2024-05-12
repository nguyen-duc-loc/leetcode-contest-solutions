// Generated by LeetCodeContestHelper at 5/12/2024, 9:38:41 AM
// 100274. Taking Maximum Energy From the Mystic Dungeon
// https://leetcode.com/contest/weekly-contest-397/problems/taking-maximum-energy-from-the-mystic-dungeon/

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
    int maximumEnergy(vector<int>& energy, int k) {
        int n = (int)energy.size();
        vector<int> dp(n);
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (i < k) {
                dp[i] = energy[i];
            } else {
                dp[i] = max(energy[i], dp[i - k] + energy[i]);
            }
            if (i + k >= n) {
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};

// int Solution::maximumEnergy(vector<int> energy, int k)

int main() {
    cout << "*** 100274. Taking Maximum Energy From the Mystic Dungeon ***"
         << endl
         << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        vector<int> energy = {5, 2, -10, -5, 1};
        int k = 3;
        int ans0 = s0.maximumEnergy(energy, k);
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

        vector<int> energy = {-2, -3, -1};
        int k = 2;
        int ans1 = s0.maximumEnergy(energy, k);
        int exp1 = -1;

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