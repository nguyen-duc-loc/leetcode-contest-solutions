// Generated by LeetCodeContestHelper at 4/30/2024, 3:53:34 AM
// 3096. Minimum Levels to Gain More Points
// https://leetcode.com/contest/biweekly-contest-127/problems/minimum-levels-to-gain-more-points/

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

template <class T = int>
struct psa {  // 0-indexed
  vector<T> prefix;

  psa() {}

  psa(vector<int> v) {
    prefix.resize(v.size() + 1);
    for (int i = 0; i < v.size(); i++)
      prefix[i + 1] = prefix[i] + v[i];
  }

  psa(vector<long long> v) {
    prefix.resize(v.size() + 1);
    for (int i = 0; i < v.size(); i++)
      prefix[i + 1] = prefix[i] + v[i];
  }

  T query(int l, int r) {
    return prefix[r + 1] - prefix[l];
  }
};

class Solution {
 public:
  int minimumLevels(vector<int>& possible) {
    int n = (int)possible.size();
    for (auto& e : possible) {
      if (e == 0) {
        e = -1;
      }
    }
    psa ps(possible);
    for (int i = 0; i < n - 1; i++) {
      if (ps.query(0, i) > ps.query(i + 1, n - 1)) {
        return i + 1;
      }
    }
    return -1;
  }
};

// int Solution::minimumLevels(vector<int> possible)

int main() {
  cout << "*** 3096. Minimum Levels to Gain More Points ***" << endl << endl;

  Solution s0;

  {
    cout << "Test 1: ";

    vector<int> possible = {1, 0, 1, 0};
    int ans0 = s0.minimumLevels(possible);
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

    vector<int> possible = {1, 1, 1, 1, 1};
    int ans1 = s0.minimumLevels(possible);
    int exp1 = 3;

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

    vector<int> possible = {0, 0};
    int ans2 = s0.minimumLevels(possible);
    int exp2 = -1;

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
