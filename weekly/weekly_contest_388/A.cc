// Generated by LeetCodeContestHelper at 4/30/2024, 3:24:01 AM
// 3074. Apple Redistribution into Boxes
// https://leetcode.com/contest/weekly-contest-388/problems/apple-redistribution-into-boxes/

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
  int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
    sort(capacity.rbegin(), capacity.rend());
    int s = 0;
    for (auto& e : apple) {
      s += e;
    }
    int t = 0, ans = 0;
    for (auto& e : capacity) {
      t += e;
      ans++;
      if (t >= s) {
        return ans;
      }
    }
    return 0;
  }
};

// int Solution::minimumBoxes(vector<int> apple, vector<int> capacity)

int main() {
  cout << "*** 3074. Apple Redistribution into Boxes ***" << endl << endl;

  Solution s0;

  {
    cout << "Test 1: ";

    vector<int> apple = {1, 3, 2};
    vector<int> capacity = {4, 3, 1, 5, 2};
    int ans0 = s0.minimumBoxes(apple, capacity);
    int exp0 = 2;

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

    vector<int> apple = {5, 5, 5};
    vector<int> capacity = {2, 4, 2, 7};
    int ans1 = s0.minimumBoxes(apple, capacity);
    int exp1 = 4;

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
