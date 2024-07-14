// Generated by LeetCodeContestHelper at 7/14/2024, 9:30:49 AM
// 100352. Lexicographically Smallest String After a Swap
// https://leetcode.com/contest/weekly-contest-406/problems/lexicographically-smallest-string-after-a-swap/

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
    string getSmallestString(string s) {
        string ans = s;
        for (int i = 0; i < (int)s.size() - 1; i++) {
            if ((s[i] - '0') % 2 == (s[i + 1] - '0') % 2) {
                swap(s[i], s[i + 1]);
                ans = min(ans, s);
                swap(s[i], s[i + 1]);
            }
        }
        return ans;
    }
};

// string Solution::getSmallestString(string s)

int main() {
    cout << "*** 100352. Lexicographically Smallest String After a Swap ***"
         << endl
         << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        string s = "45320";
        string ans0 = s0.getSmallestString(s);
        string exp0 = "43520";

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

        string s = "001";
        string ans1 = s0.getSmallestString(s);
        string exp1 = "001";

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
