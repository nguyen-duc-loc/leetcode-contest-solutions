// Generated by LeetCodeContestHelper at 4/30/2024, 3:34:32 AM
// 3133. Minimum Array End
// https://leetcode.com/contest/weekly-contest-395/problems/minimum-array-end/

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
  long long minEnd(int n, int x) {
    long long ans = 1LL * x;
    n--;
    int i = 0;
    while (n) {
      while (ans & (1LL << i)) {
        i++;
      }
      int last = (n & 1) ? 1 : 0;
      if (last) {
        ans |= (1LL << i);
      }
      i++;
      n >>= 1;
    }
    return ans;
  }
};

// long long Solution::minEnd(int n, int x)

int main() {
  cout << "*** 3133. Minimum Array End ***" << endl << endl;

  Solution s0;

  {
    cout << "Test 1: ";

    int n = 3;
    int x = 4;
    long long ans0 = s0.minEnd(n, x);
    long long exp0 = 6;

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

    int n = 2;
    int x = 7;
    long long ans1 = s0.minEnd(n, x);
    long long exp1 = 15;

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