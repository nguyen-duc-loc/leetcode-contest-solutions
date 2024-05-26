// Generated by LeetCodeContestHelper at 5/26/2024, 10:09:34 AM
// 100306. Maximum Sum of Subsequence With Non-adjacent Elements
// https://leetcode.com/contest/weekly-contest-399/problems/maximum-sum-of-subsequence-with-non-adjacent-elements/

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

const long long mod = (long long)1e9 + 7;

struct Node {
    long long max1;  // maximum [first, last]
    long long max2;  // maximum [first + 1, last]
    long long max3;  // maximum [first, last - 1]
    long long max4;  // maximum [first + 1, last - 1]

    Node() {}
};

vector<Node> tree;

void build(int index, int L, int R, vector<int>& nums) {
    if (L == R) {
        tree[index].max1 = max(0LL, 1LL * nums[L]);
        tree[index].max2 = 0LL;
        tree[index].max3 = 0LL;
        tree[index].max4 = 0LL;
        return;
    }
    int mid = (L + R) / 2;
    build(2 * index, L, mid, nums);
    build(2 * index + 1, mid + 1, R, nums);
    tree[index].max1 = max(tree[2 * index].max3 + tree[2 * index + 1].max1,
                           tree[2 * index].max1 + tree[2 * index + 1].max2);
    tree[index].max2 = max(tree[2 * index].max2 + tree[2 * index + 1].max2,
                           tree[2 * index].max4 + tree[2 * index + 1].max1);
    tree[index].max3 = max(tree[2 * index].max1 + tree[2 * index + 1].max4,
                           tree[2 * index].max3 + tree[2 * index + 1].max3);
    tree[index].max4 = max(tree[2 * index].max2 + tree[2 * index + 1].max4,
                           tree[2 * index].max4 + tree[2 * index + 1].max3);
}

void update(int index, int L, int R, int pos, int val) {
    if (L == R) {
        tree[index].max1 = max(0LL, 1LL * val);
        tree[index].max2 = 0LL;
        tree[index].max3 = 0LL;
        tree[index].max4 = 0LL;
        return;
    }
    int mid = (L + R) / 2;
    if (pos <= mid) {
        update(2 * index, L, mid, pos, val);
    } else {
        update(2 * index + 1, mid + 1, R, pos, val);
    }
    tree[index].max1 = max(tree[2 * index].max3 + tree[2 * index + 1].max1,
                           tree[2 * index].max1 + tree[2 * index + 1].max2);
    tree[index].max2 = max(tree[2 * index].max2 + tree[2 * index + 1].max2,
                           tree[2 * index].max4 + tree[2 * index + 1].max1);
    tree[index].max3 = max(tree[2 * index].max1 + tree[2 * index + 1].max4,
                           tree[2 * index].max3 + tree[2 * index + 1].max3);
    tree[index].max4 = max(tree[2 * index].max2 + tree[2 * index + 1].max4,
                           tree[2 * index].max4 + tree[2 * index + 1].max3);
}

class Solution {
   public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n = (int)nums.size();
        tree.clear();
        tree.resize(4 * n + 5);
        build(1, 0, n - 1, nums);
        long long ans = 0;

        for (auto& e : queries) {
            update(1, 0, n - 1, e[0], e[1]);
            ans += tree[1].max1;
            ans %= mod;
        }
        return ans;
    }
};

// int Solution::maximumSumSubsequence(vector<int> nums, vector<vector<int>>
// queries)

int main() {
    cout << "*** 100306. Maximum Sum of Subsequence With Non-adjacent Elements "
            "***"
         << endl
         << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        vector<int> nums = {3, 5, 9};
        vector<vector<int>> queries = {{1, -2}, {0, -3}};
        int ans0 = s0.maximumSumSubsequence(nums, queries);
        int exp0 = 21;

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

        vector<int> nums = {0, -1};
        vector<vector<int>> queries = {{0, -5}};
        int ans1 = s0.maximumSumSubsequence(nums, queries);
        int exp1 = 0;

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
