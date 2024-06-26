// Generated by LeetCodeContestHelper at 5/1/2024, 7:30:12 AM
// 3010. Divide an Array Into Subarrays With Minimum Cost I
// https://leetcode.com/contest/biweekly-contest-122/problems/divide-an-array-into-subarrays-with-minimum-cost-i/

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
    int minimumCost(vector<int>& nums) {
        sort(nums.begin() + 1, nums.end());
        return nums[0] + nums[1] + nums[2];
    }
};

// int Solution::minimumCost(vector<int> nums)

int main() {
    cout << "*** 3010. Divide an Array Into Subarrays With Minimum Cost I ***"
         << endl
         << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        vector<int> nums = {1, 2, 3, 12};
        int ans0 = s0.minimumCost(nums);
        int exp0 = 6;

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

        vector<int> nums = {5, 4, 3};
        int ans1 = s0.minimumCost(nums);
        int exp1 = 12;

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

        vector<int> nums = {10, 3, 1, 1};
        int ans2 = s0.minimumCost(nums);
        int exp2 = 12;

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
