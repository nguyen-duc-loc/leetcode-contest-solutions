// Generated by LeetCodeContestHelper at 6/8/2024, 9:31:41 PM
// 100324. Clear Digits
// https://leetcode.com/contest/biweekly-contest-132/problems/clear-digits/

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
    string clearDigits(string s) {
        stack<char> st;
        int n = (int)s.size();
        vector<bool> v(n, 1);
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                if (!st.empty()) {
                    v[st.top()] = 0;
                    st.pop();
                }
                v[i] = 0;
            } else {
                st.push(i);
            }
        }
        string ans;
        for (int i = 0; i < n; i++) {
            if (v[i]) {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};

// string Solution::clearDigits(string s)

int main() {
    cout << "*** 100324. Clear Digits ***" << endl << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        string s = "abc";
        string ans0 = s0.clearDigits(s);
        string exp0 = "abc";

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

        string s = "cb34";
        string ans1 = s0.clearDigits(s);
        string exp1 = "";

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
