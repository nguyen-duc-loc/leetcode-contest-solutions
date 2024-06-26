// Generated by LeetCodeContestHelper at 4/30/2024, 3:34:36 AM
// 3134. Find the Median of the Uniqueness Array
// https://leetcode.com/contest/weekly-contest-395/problems/find-the-median-of-the-uniqueness-array/

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
    int medianOfUniquenessArray(vector<int>& nums) {
        int n = (int)nums.size();
        int low = 1, high = n;
        int ans;
        while (low <= high) {
            int mid = (low + high) / 2;
            vector<int> cnt(100001);
            int cur = 0, l = 0;
            long long t = 0;
            for (int i = 0; i < n; i++) {
                cnt[nums[i]]++;
                if (cnt[nums[i]] == 1) {
                    cur++;
                }
                while (cur > mid) {
                    cnt[nums[l]]--;
                    if (cnt[nums[l]] == 0) {
                        cur--;
                    }
                    l++;
                }
                t += i - l + 1;
            }
            if (2 * t >= 1LL * n * (n + 1) / 2) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

// int Solution::medianOfUniquenessArray(vector<int> nums)

int main() {
    cout << "*** 3134. Find the Median of the Uniqueness Array ***" << endl
         << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        vector<int> nums = {1, 2, 3};
        int ans0 = s0.medianOfUniquenessArray(nums);
        int exp0 = 1;

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

        vector<int> nums = {3, 4, 3, 4, 5};
        int ans1 = s0.medianOfUniquenessArray(nums);
        int exp1 = 2;

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

        vector<int> nums = {4, 3, 5, 4};
        int ans2 = s0.medianOfUniquenessArray(nums);
        int exp2 = 2;

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
