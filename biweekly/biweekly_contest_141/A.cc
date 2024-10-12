// Generated by LeetCodeContestHelper at 10/12/2024, 9:34:57 PM
// 100451. Construct the Minimum Bitwise Array I
// https://leetcode.com/contest/biweekly-contest-141/problems/construct-the-minimum-bitwise-array-i/

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
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (auto& e : nums) {
            bool ok = 0;
            for (int i = 0; i < e; i++) {
                if ((i | (i + 1)) == e) {
                    ans.push_back(i);
                    ok = 1;
                    break;
                }
            }
            if (!ok) {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

// vector<int> Solution::minBitwiseArray(vector<int> nums)

int main() {
    cout << "*** 100451. Construct the Minimum Bitwise Array I ***" << endl
         << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        vector<int> nums = {2, 3, 5, 7};
        vector<int> ans0 = s0.minBitwiseArray(nums);
        vector<int> exp0 = {-1, 1, 4, 3};

        if (ans0 == exp0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
            cout << "  Answer: ";
            for (int& i : ans0) {
                cout << i << " ";
            }
            cout << endl << "  Expect: ";
            for (int& i : exp0) {
                cout << i << " ";
            }
            cout << endl;
        }
    }

    {
        cout << "Test 2: ";

        vector<int> nums = {11, 13, 31};
        vector<int> ans1 = s0.minBitwiseArray(nums);
        vector<int> exp1 = {9, 12, 15};

        if (ans1 == exp1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
            cout << "  Answer: ";
            for (int& i : ans1) {
                cout << i << " ";
            }
            cout << endl << "  Expect: ";
            for (int& i : exp1) {
                cout << i << " ";
            }
            cout << endl;
        }
    }

    return 0;
}