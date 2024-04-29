// Generated by LeetCodeContestHelper at 4/30/2024, 3:13:49 AM
// 3046. Split the Array
// https://leetcode.com/contest/weekly-contest-386/problems/split-the-array/

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
  bool isPossibleToSplit(vector<int>& nums) {
    unordered_map<int, int> mp;
    for (auto& e : nums) {
      mp[e]++;
    }
    for (auto& e : mp) {
      if (e.second > 2) {
        return false;
      }
    }
    return true;
  }
};

// bool Solution::isPossibleToSplit(vector<int> nums)

int main() {
  cout << "*** 3046. Split the Array ***" << endl << endl;

  Solution s0;

  {
    cout << "Test 1: ";

    vector<int> nums = {1, 1, 2, 2, 3, 4};
    bool ans0 = s0.isPossibleToSplit(nums);
    bool exp0 = true;

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

    vector<int> nums = {1, 1, 1, 1};
    bool ans1 = s0.isPossibleToSplit(nums);
    bool exp1 = false;

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