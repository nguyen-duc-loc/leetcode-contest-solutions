// Generated by LeetCodeContestHelper at 6/2/2024, 3:03:51 PM
// 3168. Minimum Number of Chairs in a Waiting Room
// https://leetcode.com/contest/weekly-contest-400/problems/minimum-number-of-chairs-in-a-waiting-room/

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
    int minimumChairs(string s) {
        int a = 0, ans = 0;
        for (auto& e : s) {
            a += (e == 'E');
            a -= (e == 'L');
            ans = max(ans, a);
        }
        return ans;
    }
};

// int Solution::minimumChairs(string s)

int main() {
    cout << "*** 3168. Minimum Number of Chairs in a Waiting Room ***" << endl
         << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        string s = "EEEEEEE";
        int ans0 = s0.minimumChairs(s);
        int exp0 = 7;

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

        string s = "ELELEEL";
        int ans1 = s0.minimumChairs(s);
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

        string s = "ELEELEELLL";
        int ans2 = s0.minimumChairs(s);
        int exp2 = 3;

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