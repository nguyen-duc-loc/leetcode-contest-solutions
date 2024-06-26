// Generated by LeetCodeContestHelper at 4/30/2024, 3:36:11 AM
// 3066. Minimum Operations to Exceed Threshold Value II
// https://leetcode.com/contest/biweekly-contest-125/problems/minimum-operations-to-exceed-threshold-value-ii/

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
        priority_queue<long long, vector<long long>, greater<long long>> q;
        for (auto& e : nums) {
            q.push(1LL * e);
        }
        int ans = 0;
        while ((int)q.size() >= 2 && q.top() < k) {
            long long x = q.top();
            q.pop();
            long long y = q.top();
            q.pop();
            ans++;
            q.push(x * 2 + y);
        }
        return ans;
    }
};

// int Solution::minOperations(vector<int> nums, int k)

int main() {
    cout << "*** 3066. Minimum Operations to Exceed Threshold Value II ***"
         << endl
         << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        vector<int> nums = {2, 11, 10, 1, 3};
        int k = 10;
        int ans0 = s0.minOperations(nums, k);
        int exp0 = 2;

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
        int k = 20;
        int ans1 = s0.minOperations(nums, k);
        int exp1 = 4;

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
