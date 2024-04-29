// Generated by LeetCodeContestHelper at 4/30/2024, 3:15:08 AM
// 3049. Earliest Second to Mark Indices II
// https://leetcode.com/contest/weekly-contest-386/problems/earliest-second-to-mark-indices-ii/

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
  int earliestSecondToMarkIndices(vector<int>& nums,
                                  vector<int>& changeIndices) {
    const long long numsSum = accumulate(nums.begin(), nums.end(), 0LL);
    const unordered_map<int, int> secondToIndex =
        getSecondToIndex(nums, changeIndices);
    int l = 0;
    int r = changeIndices.size() + 1;

    while (l < r) {
      const int m = (l + r) / 2;
      if (canMark(nums, secondToIndex, m, numsSum))
        r = m;
      else
        l = m + 1;
    }

    return l <= changeIndices.size() ? l : -1;
  }

 private:
  bool canMark(const vector<int>& nums,
               const unordered_map<int, int>& secondToIndex, int maxSecond,
               const long long numsSum) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int marks = 0;

    for (int second = maxSecond - 1; second >= 0; --second) {
      if (const auto it = secondToIndex.find(second);
          it != secondToIndex.end()) {
        const int index = it->second;
        minHeap.push(nums[index]);
        if (marks == 0) {
          minHeap.pop();
          ++marks;
        } else {
          --marks;
        }
      } else {
        ++marks;
      }
    }

    const int heapSize = minHeap.size();
    const long long decrementAndMarkCost =
        numsSum - getHeapSum(minHeap) + (nums.size() - heapSize);
    const long long zeroAndMarkCost = heapSize + heapSize;
    return decrementAndMarkCost + zeroAndMarkCost <= maxSecond;
  }

  long long getHeapSum(priority_queue<int, vector<int>, greater<int>>& heap) {
    long long heapSum = 0;
    while (!heap.empty())
      heapSum += heap.top(), heap.pop();
    return heapSum;
  }

  unordered_map<int, int> getSecondToIndex(const vector<int>& nums,
                                           const vector<int>& changeIndices) {
    unordered_map<int, int> indexToFirstSecond;
    unordered_map<int, int> secondToIndex;
    for (int zeroIndexedSecond = 0; zeroIndexedSecond < changeIndices.size();
         ++zeroIndexedSecond) {
      const int index = changeIndices[zeroIndexedSecond] - 1;
      if (nums[index] > 0 && !indexToFirstSecond.count(index))
        indexToFirstSecond[index] = zeroIndexedSecond;
    }
    for (const auto& [index, second] : indexToFirstSecond)
      secondToIndex[second] = index;
    return secondToIndex;
  }
};

// int Solution::earliestSecondToMarkIndices(vector<int> nums, vector<int>
// changeIndices)

int main() {
  cout << "*** 3049. Earliest Second to Mark Indices II ***" << endl << endl;

  Solution s0;

  {
    cout << "Test 1: ";

    vector<int> nums = {3, 2, 3};
    vector<int> changeIndices = {1, 3, 2, 2, 2, 2, 3};
    int ans0 = s0.earliestSecondToMarkIndices(nums, changeIndices);
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

    vector<int> nums = {0, 0, 1, 2};
    vector<int> changeIndices = {1, 2, 1, 2, 1, 2, 1, 2};
    int ans1 = s0.earliestSecondToMarkIndices(nums, changeIndices);
    int exp1 = 7;

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

    vector<int> nums = {1, 2, 3};
    vector<int> changeIndices = {1, 2, 3};
    int ans2 = s0.earliestSecondToMarkIndices(nums, changeIndices);
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
