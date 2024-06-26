// Generated by LeetCodeContestHelper at 4/30/2024, 3:35:52 AM
// 3065. Minimum Operations to Exceed Threshold Value I
// https://leetcode.com/contest/biweekly-contest-125/problems/minimum-operations-to-exceed-threshold-value-i/

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
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] < k) {
                ans++;
            }
        }
        return ans;
    }
};

// int Solution::minOperations(vector<int> nums, int k)

int main() {
    cout << "*** 3065. Minimum Operations to Exceed Threshold Value I ***"
         << endl
         << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        vector<int> nums = {2, 11, 10, 1, 3};
        int k = 10;
        int ans0 = s0.minOperations(nums, k);
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

        vector<int> nums = {1, 1, 2, 4, 9};
        int k = 1;
        int ans1 = s0.minOperations(nums, k);
        int exp1 = 0;

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

        vector<int> nums = {1, 1, 2, 4, 9};
        int k = 9;
        int ans2 = s0.minOperations(nums, k);
        int exp2 = 4;

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
