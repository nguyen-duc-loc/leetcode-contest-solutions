// Generated by LeetCodeContestHelper at 5/21/2024, 11:49:32 AM
// 1507. Reformat Date
// https://leetcode.com/contest/biweekly-contest-30/problems/reformat-date/

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
    string reformatDate(string date) {
        vector<string> v;
        stringstream ss(date);
        string w;
        while (ss >> w) {
            v.push_back(w);
        }
        reverse(v.begin(), v.end());
        vector<string> a = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        string ans;
        ans += v.front() + "-";
        int i = 0;
        while (a[i] != v[1]) {
            i++;
        }
        i++;
        ans += (i < 10 ? "0" : "") + to_string(i) + "-";
        string d = string(v.back().begin(), --(--v.back().end()));
        ans += (d.size() < 2 ? "0" : "") + d;
        return ans;
    }
};

// string Solution::reformatDate(string date)

int main() {
    cout << "*** 1507. Reformat Date ***" << endl << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        string date = "20th Oct 2052";
        string ans0 = s0.reformatDate(date);
        string exp0 = "2052-10-20";

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

        string date = "6th Jun 1933";
        string ans1 = s0.reformatDate(date);
        string exp1 = "1933-06-06";

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

        string date = "26th May 1960";
        string ans2 = s0.reformatDate(date);
        string exp2 = "1960-05-26";

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