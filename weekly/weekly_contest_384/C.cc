// Generated by LeetCodeContestHelper at 5/1/2024, 4:58:44 PM
// 3035. Maximum Palindromes After Operations
// https://leetcode.com/contest/weekly-contest-384/problems/maximum-palindromes-after-operations/

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
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int> v(26);
        for (auto& e : words) {
            for (auto& x : e) {
                v[x - 'a']++;
            }
        }
        int n = 0;
        for (auto& e : v) {
            n += e / 2;
        }
        vector<int> v2;
        for (auto& e : words) {
            v2.push_back((int)e.size());
        }
        sort(v2.begin(), v2.end());
        int ans = 0;
        for (auto& e : v2) {
            if (n >= e / 2) {
                n -= e / 2;
                ans++;
            }
        }
        return ans;
    }
};

// int Solution::maxPalindromesAfterOperations(vector<string> words)

int main() {
    cout << "*** 3035. Maximum Palindromes After Operations ***" << endl
         << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        vector<string> words = {"abbb", "ba", "aa"};
        int ans0 = s0.maxPalindromesAfterOperations(words);
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

        vector<string> words = {"abc", "ab"};
        int ans1 = s0.maxPalindromesAfterOperations(words);
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

        vector<string> words = {"cd", "ef", "a"};
        int ans2 = s0.maxPalindromesAfterOperations(words);
        int exp2 = 1;

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