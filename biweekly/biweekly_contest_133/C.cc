// Generated by LeetCodeContestHelper at 6/22/2024, 9:38:58 PM
// 100346. Minimum Operations to Make Binary Array Elements Equal to One II
// https://leetcode.com/contest/biweekly-contest-133/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii/

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
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for (auto& e : nums) {
            if (!e && ans % 2 == 0) {
                ans++;
            }
            if (e && ans % 2) {
                ans++;
            }
        }
        return ans;
    }
};

// int Solution::minOperations(vector<int> nums)

int main() {
    cout << "*** 100346. Minimum Operations to Make Binary Array Elements "
            "Equal to One II ***"
         << endl
         << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        vector<int> nums = {0, 1, 1, 0, 1};
        int ans0 = s0.minOperations(nums);
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

        vector<int> nums = {1, 0, 0, 0};
        int ans1 = s0.minOperations(nums);
        int exp1 = 1;

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
