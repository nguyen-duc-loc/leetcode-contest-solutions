// Generated by LeetCodeContestHelper at 5/1/2024, 4:58:39 PM
// 3034. Number of Subarrays That Match a Pattern I
// https://leetcode.com/contest/weekly-contest-384/problems/number-of-subarrays-that-match-a-pattern-i/

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
  int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
    int ans = 0;
    int n = (int)nums.size();
    vector<long long> hashed = {0};
    const long long mod = (long long)1e9 + 7;
    const long long p = 31;
    long long power = 1;
    for (int i = 1; i < n; i++) {
      int x;
      if (nums[i] > nums[i - 1])
        x = 1;
      else if (nums[i] == nums[i - 1])
        x = 0;
      else
        x = -1;
      hashed.push_back((hashed.back() + (x + 2) * power) % mod);
      power = (power * p) % mod;
    }
    long long a = p, b = mod - 2, pm = 1;
    while (b) {
      if (b & 1)
        pm *= a;
      pm %= mod;
      a *= a;
      a %= mod;
      b >>= 1;
    }
    vector<long long> pow = {1, 1};
    for (int i = 2; i <= n; i++) {
      pow.push_back((pow.back() * pm) % mod);
    }
    long long h = 0;
    power = 1;
    for (auto& e : pattern) {
      h += (e + 2) * power;
      h %= mod;
      power = (power * p) % mod;
    }
    int sz = (int)pattern.size();
    for (int i = sz; i < n; i++) {
      long long h2 =
          ((hashed[i] - hashed[i - sz] + mod) % mod) * pow[i - sz + 1];
      h2 %= mod;
      ans += (h2 == h);
    }
    return ans;
  }
};

// int Solution::countMatchingSubarrays(vector<int> nums, vector<int> pattern)

int main() {
  cout << "*** 3034. Number of Subarrays That Match a Pattern I ***" << endl
       << endl;

  Solution s0;

  {
    cout << "Test 1: ";

    vector<int> nums = {1, 2, 3, 4, 5, 6};
    vector<int> pattern = {1, 1};
    int ans0 = s0.countMatchingSubarrays(nums, pattern);
    int exp0 = 4;

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

    vector<int> nums = {1, 4, 4, 1, 3, 5, 5, 3};
    vector<int> pattern = {1, 0, -1};
    int ans1 = s0.countMatchingSubarrays(nums, pattern);
    int exp1 = 2;

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
