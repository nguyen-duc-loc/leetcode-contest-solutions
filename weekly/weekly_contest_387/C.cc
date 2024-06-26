// Generated by LeetCodeContestHelper at 4/30/2024, 3:21:05 AM
// 3071. Minimum Operations to Write the Letter Y on a Grid
// https://leetcode.com/contest/weekly-contest-387/problems/minimum-operations-to-write-the-letter-y-on-a-grid/

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
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        vector<int> v1(3);
        vector<int> v2(3);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                v2[grid[i][j]]++;
            }
        }
        for (int i = 0; i <= n / 2; i++) {
            v1[grid[i][i]]++;
        }
        for (int i = n - 1; i > n / 2; i--) {
            v1[grid[n - i - 1][i]]++;
        }
        for (int i = n / 2 + 1; i < n; i++) {
            v1[grid[i][n / 2]]++;
        }
        for (int i = 0; i < 3; i++) {
            v2[i] -= v1[i];
        }
        int m1 = v1[1] + v1[2] + v2[0] + min(v2[1], v2[2]);
        int m2 = v1[0] + v1[2] + v2[1] + min(v2[0], v2[2]);
        int m3 = v1[0] + v1[1] + v2[2] + min(v2[0], v2[1]);
        return min({m1, m2, m3});
    }
};

// int Solution::minimumOperationsToWriteY(vector<vector<int>> grid)

int main() {
    cout << "*** 3071. Minimum Operations to Write the Letter Y on a Grid ***"
         << endl
         << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        vector<vector<int>> grid = {{1, 2, 2}, {1, 1, 0}, {0, 1, 0}};
        int ans0 = s0.minimumOperationsToWriteY(grid);
        int exp0 = 3;

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

        vector<vector<int>> grid = {{0, 1, 0, 1, 0},
                                    {2, 1, 0, 1, 2},
                                    {2, 2, 2, 0, 1},
                                    {2, 2, 2, 2, 2},
                                    {2, 1, 2, 2, 2}};
        int ans1 = s0.minimumOperationsToWriteY(grid);
        int exp1 = 12;

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
