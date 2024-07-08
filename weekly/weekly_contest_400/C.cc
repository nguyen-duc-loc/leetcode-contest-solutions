// Generated by LeetCodeContestHelper at 6/2/2024, 2:31:57 PM
// 3170. Lexicographically Minimum String After Removing Stars
// https://leetcode.com/contest/weekly-contest-400/problems/lexicographically-minimum-string-after-removing-stars/

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
    string clearStars(string s) {
        int n = (int)s.size();
        vector<bool> del(n);
        vector<vector<int>> v(26);
        for (int i = 0; i < (int)s.size(); i++) {
            char c = s[i];
            if (c == '*') {
                for (auto& e : v) {
                    if (!e.empty()) {
                        del[e.back()] = 1;
                        e.pop_back();
                        break;
                    }
                }
                del[i] = 1;
            } else {
                v[c - 'a'].push_back(i);
            }
        }
        string ans;
        for (int i = 0; i < n; i++) {
            if (!del[i]) {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};

// string Solution::clearStars(string s)

int main() {
    cout
        << "*** 3170. Lexicographically Minimum String After Removing Stars ***"
        << endl
        << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        string s = "aaba*";
        string ans0 = s0.clearStars(s);
        string exp0 = "aab";

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

        string s = "abc";
        string ans1 = s0.clearStars(s);
        string exp1 = "abc";

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