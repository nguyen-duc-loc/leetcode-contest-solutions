// Generated by LeetCodeContestHelper at 4/30/2024, 3:14:07 AM
// 3047. Find the Largest Area of Square Inside Two Rectangles
// https://leetcode.com/contest/weekly-contest-386/problems/find-the-largest-area-of-square-inside-two-rectangles/

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
  long long area(int x1, int y1, int x2, int y2, int x3, int y3, int x4,
                 int y4) {
    int _x1 = max(x1, x3);
    int _y1 = max(y1, y3);
    int _x2 = min(x2, x4);
    int _y2 = min(y2, y4);
    int n = min(_x2 - _x1, _y2 - _y1);
    n = max(n, 0);
    long long ans = 1LL * n * n;
    return ans;
  }

  long long largestSquareArea(vector<vector<int>>& bottomLeft,
                              vector<vector<int>>& topRight) {
    int n = (int)bottomLeft.size();
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        ans = max(ans, area(bottomLeft[i][0], bottomLeft[i][1], topRight[i][0],
                            topRight[i][1], bottomLeft[j][0], bottomLeft[j][1],
                            topRight[j][0], topRight[j][1]));
      }
    }
    return ans;
  }
};

// long long Solution::largestSquareArea(vector<vector<int>> bottomLeft,
// vector<vector<int>> topRight)

int main() {
  cout << "*** 3047. Find the Largest Area of Square Inside Two Rectangles ***"
       << endl
       << endl;

  Solution s0;

  {
    cout << "Test 1: ";

    vector<vector<int>> bottomLeft = {{1, 1}, {2, 2}, {3, 1}};
    vector<vector<int>> topRight = {{3, 3}, {4, 4}, {6, 6}};
    long long ans0 = s0.largestSquareArea(bottomLeft, topRight);
    long long exp0 = 1;

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

    vector<vector<int>> bottomLeft = {{1, 1}, {2, 2}, {1, 2}};
    vector<vector<int>> topRight = {{3, 3}, {4, 4}, {3, 4}};
    long long ans1 = s0.largestSquareArea(bottomLeft, topRight);
    long long exp1 = 1;

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

    vector<vector<int>> bottomLeft = {{1, 1}, {3, 3}, {3, 1}};
    vector<vector<int>> topRight = {{2, 2}, {4, 4}, {4, 2}};
    long long ans2 = s0.largestSquareArea(bottomLeft, topRight);
    long long exp2 = 0;

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
