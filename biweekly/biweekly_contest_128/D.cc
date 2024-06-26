// Generated by LeetCodeContestHelper at 4/30/2024, 3:54:31 AM
// 3113. Find the Number of Subarrays Where Boundary Elements Are Maximum
// https://leetcode.com/contest/biweekly-contest-128/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/

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
    long long ans = 0;

    void combine(int L, int R, int mid, vector<int>& nums) {
        map<pair<int, int>, long long> mp;
        int cur = INT_MIN;
        for (int i = mid + 1; i <= R; i++) {
            cur = max(cur, nums[i]);
            mp[{nums[i], cur}]++;
        }
        cur = INT_MIN;
        for (int i = mid; i >= L; i--) {
            if (nums[i] >= cur) {
                ans += mp[{nums[i], nums[i]}];
                cur = nums[i];
            }
        }
    }

    void mergeSort(int L, int R, vector<int>& nums) {
        if (L == R) {
            ans++;
            return;
        }
        int mid = (L + R) / 2;
        mergeSort(L, mid, nums);
        mergeSort(mid + 1, R, nums);
        combine(L, R, mid, nums);
    }

    long long numberOfSubarrays(vector<int>& nums) {
        ans = 0;
        int n = (int)nums.size();
        mergeSort(0, n - 1, nums);
        return ans;
    }
};

// long long Solution::numberOfSubarrays(vector<int> nums)

int main() {
    cout
        << "*** 3113. Find the Number of Subarrays Where Boundary Elements Are "
           "Maximum ***"
        << endl
        << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        vector<int> nums = {1, 4, 3, 3, 2};
        long long ans0 = s0.numberOfSubarrays(nums);
        long long exp0 = 6;

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

        vector<int> nums = {3, 3, 3};
        long long ans1 = s0.numberOfSubarrays(nums);
        long long exp1 = 6;

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

        vector<int> nums = {1};
        long long ans2 = s0.numberOfSubarrays(nums);
        long long exp2 = 1;

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
