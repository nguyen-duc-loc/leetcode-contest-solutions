// Generated by LeetCodeContestHelper at 4/30/2024, 3:34:18 AM
// 3131. Find the Integer Added to Array I
// https://leetcode.com/contest/weekly-contest-395/problems/find-the-integer-added-to-array-i/

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
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        return nums2.front() - nums1.front();
    }
};

// int Solution::addedInteger(vector<int> nums1, vector<int> nums2)

int main() {
    cout << "*** 3131. Find the Integer Added to Array I ***" << endl << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        vector<int> nums1 = {2, 6, 4};
        vector<int> nums2 = {9, 7, 5};
        int ans0 = s0.addedInteger(nums1, nums2);
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

        vector<int> nums1 = {10};
        vector<int> nums2 = {5};
        int ans1 = s0.addedInteger(nums1, nums2);
        int exp1 = -5;

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

        vector<int> nums1 = {1, 1, 1, 1};
        vector<int> nums2 = {1, 1, 1, 1};
        int ans2 = s0.addedInteger(nums1, nums2);
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
