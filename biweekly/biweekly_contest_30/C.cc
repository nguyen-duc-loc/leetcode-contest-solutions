// Generated by LeetCodeContestHelper at 5/21/2024, 11:49:44 AM
// 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
// https://leetcode.com/contest/biweekly-contest-30/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/

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
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        if (n <= 3)
            return 0;
        int ans = INT_MAX;
        for (int i = 0; i <= 3; i++) {
            ans = min(ans, abs(nums[n - 1 - i] - nums[3 - i]));
        }
        return ans;
    }
};

// int Solution::minDifference(vector<int> nums)

int main() {
    cout << "*** 1509. Minimum Difference Between Largest and Smallest Value "
            "in Three Moves ***"
         << endl
         << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        vector<int> nums = {5, 3, 2, 4};
        int ans0 = s0.minDifference(nums);
        int exp0 = 0;

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

        vector<int> nums = {1, 5, 0, 10, 14};
        int ans1 = s0.minDifference(nums);
        int exp1 = 1;

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

        vector<int> nums = {3, 100, 20};
        int ans2 = s0.minDifference(nums);
        int exp2 = 0;

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
