// Generated by LeetCodeContestHelper at 4/30/2024, 3:32:50 AM
// 3115. Maximum Prime Difference
// https://leetcode.com/contest/weekly-contest-393/problems/maximum-prime-difference/

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
    bool isPrime(int n) {
        if (n < 2) {
            return false;
        }
        for (int i = 2; i <= (int)sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int maximumPrimeDifference(vector<int>& nums) {
        int mx = -1, mn = INT_MAX;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (isPrime(nums[i])) {
                mx = max(mx, i);
                mn = min(mn, i);
            }
        }
        return mx - mn;
    }
};

// int Solution::maximumPrimeDifference(vector<int> nums)

int main() {
    cout << "*** 3115. Maximum Prime Difference ***" << endl << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        vector<int> nums = {4, 2, 9, 5, 3};
        int ans0 = s0.maximumPrimeDifference(nums);
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

        vector<int> nums = {4, 8, 2, 8};
        int ans1 = s0.maximumPrimeDifference(nums);
        int exp1 = 0;

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
