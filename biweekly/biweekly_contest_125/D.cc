// Generated by LeetCodeContestHelper at 4/30/2024, 3:37:10 AM
// 3068. Find the Maximum Sum of Node Values
// https://leetcode.com/contest/biweekly-contest-125/problems/find-the-maximum-sum-of-node-values/

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
  long long maximumValueSum(vector<int>& nums, int k,
                            vector<vector<int>>& edges) {
    long long maxSum = 0;
    int changedCount = 0;
    int minChangeDiff = INT_MAX;

    for (const int num : nums) {
      maxSum += max(num, num ^ k);
      changedCount += ((num ^ k) > num) ? 1 : 0;
      minChangeDiff = min(minChangeDiff, abs(num - (num ^ k)));
    }

    if (changedCount % 2 == 0)
      return maxSum;
    return maxSum - minChangeDiff;
  }
};

// long long Solution::maximumValueSum(vector<int> nums, int k,
// vector<vector<int>> edges)

int main() {
  cout << "*** 3068. Find the Maximum Sum of Node Values ***" << endl << endl;

  Solution s0;

  {
    cout << "Test 1: ";

    vector<int> nums = {1, 2, 1};
    int k = 3;
    vector<vector<int>> edges = {{0, 1}, {0, 2}};
    long long ans0 = s0.maximumValueSum(nums, k, edges);
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

    vector<int> nums = {2, 3};
    int k = 7;
    vector<vector<int>> edges = {{0, 1}};
    long long ans1 = s0.maximumValueSum(nums, k, edges);
    long long exp1 = 9;

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

    vector<int> nums = {7, 7, 7, 7, 7, 7};
    int k = 3;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}};
    long long ans2 = s0.maximumValueSum(nums, k, edges);
    long long exp2 = 42;

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