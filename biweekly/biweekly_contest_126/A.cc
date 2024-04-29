// Generated by LeetCodeContestHelper at 4/30/2024, 3:38:50 AM
// 3079. Find the Sum of Encrypted Integers
// https://leetcode.com/contest/biweekly-contest-126/problems/find-the-sum-of-encrypted-integers/

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
  int sumOfEncryptedInt(vector<int>& nums) {
    int ans = 0;
    for (auto& e : nums) {
      string s = to_string(e);
      char c = *max_element(s.begin(), s.end());
      string t(s.size(), c);
      ans += stoi(t);
    }
    return ans;
  }
};

// int Solution::sumOfEncryptedInt(vector<int> nums)

int main() {
  cout << "*** 3079. Find the Sum of Encrypted Integers ***" << endl << endl;

  Solution s0;

  {
    cout << "Test 1: ";

    vector<int> nums = {1, 2, 3};
    int ans0 = s0.sumOfEncryptedInt(nums);
    int exp0 = 6;

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

    vector<int> nums = {10, 21, 31};
    int ans1 = s0.sumOfEncryptedInt(nums);
    int exp1 = 66;

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