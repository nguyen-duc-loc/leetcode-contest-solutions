// Generated by LeetCodeContestHelper at 6/2/2024, 3:21:06 PM
// 3171. Find Subarray With Bitwise AND Closest to K
// https://leetcode.com/contest/weekly-contest-400/problems/find-subarray-with-bitwise-and-closest-to-k/

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
struct sparseTable {  // 0-indexed
    T op(T a, T b) {
        return a & b;
    }

    int n;
    vector<vector<T>> st;

    sparseTable() {}

    sparseTable(vector<T> v) {
        n = v.size();
        st = vector<vector<T>>(__lg(n) + 1, vector<T>(n));
        st[0] = v;
        for (int i = 1; i < st.size(); i++) {
            for (int j = 0; j + (1 << i) <= n; j++)
                st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }

    T query(int l, int r) {  // inclusive range
        int sz = __lg(r - l + 1);
        return op(st[sz][l], st[sz][r - (1 << sz) + 1]);
    }
};

class Solution {
   public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = (int)nums.size(), ans = INT_MAX;
        sparseTable st(nums);
        for (int i = 0; i < n; i++) {
            int low = i, high = n - 1;
            while (low <= high) {
                int mid = (low + high) >> 1;
                int c = st.query(i, mid);
                if (c > k) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
                ans = min(ans, abs(k - c));
            }
        }
        return ans;
    }
};

// int Solution::minimumDifference(vector<int> nums, int k)

int main() {
    cout << "*** 3171. Find Subarray With Bitwise AND Closest to K ***" << endl
         << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        vector<int> nums = {1, 2, 4, 5};
        int k = 3;
        int ans0 = s0.minimumDifference(nums, k);
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

        vector<int> nums = {1, 2, 1, 2};
        int k = 2;
        int ans1 = s0.minimumDifference(nums, k);
        int exp1 = 0;

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

        vector<int> nums = {1};
        int k = 10;
        int ans2 = s0.minimumDifference(nums, k);
        int exp2 = 9;

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
