// Generated by LeetCodeContestHelper at 4/30/2024, 3:39:37 AM
// 3081. Replace Question Marks in String to Minimize Its Value
// https://leetcode.com/contest/biweekly-contest-126/problems/replace-question-marks-in-string-to-minimize-its-value/

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
  string minimizeStringValue(string s) {
    set<pair<int, char>> st;
    for (char c = 'a'; c <= 'z'; c++) {
      st.insert(make_pair(count(s.begin(), s.end(), c), c));
    }
    vector<int> v;
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] == '?') {
        v.push_back(i);
      }
    }
    for (auto& e : s) {
      if (e == '?') {
        auto it = st.begin();
        e = it->second;
        int c = it->first;
        st.erase(it);
        st.insert(make_pair(c + 1, e));
      }
    }
    vector<char> t;
    for (auto& e : v) {
      t.push_back(s[e]);
    }
    sort(t.begin(), t.end());
    for (int i = 0; i < (int)t.size(); i++) {
      s[v[i]] = t[i];
    }
    return s;
  }
};

// string Solution::minimizeStringValue(string s)

int main() {
  cout << "*** 3081. Replace Question Marks in String to Minimize Its Value ***"
       << endl
       << endl;

  Solution s0;

  {
    cout << "Test 1: ";

    string s = "???";
    string ans0 = s0.minimizeStringValue(s);
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

    string s = "a?a?";
    string ans1 = s0.minimizeStringValue(s);
    string exp1 = "abac";

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
