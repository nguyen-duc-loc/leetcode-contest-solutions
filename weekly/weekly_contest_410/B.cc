// Generated by LeetCodeContestHelper at 8/11/2024, 9:35:21 AM
// 100354. Count the Number of Good Nodes
// https://leetcode.com/contest/weekly-contest-410/problems/count-the-number-of-good-nodes/

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
    vector<vector<int>> adj;
    int ans = 0;

    int dfs(int u, int p) {
        int c = 1, cur = -1;
        bool ok = 1;
        for (auto& e : adj[u]) {
            if (e != p) {
                int sz = dfs(e, u);
                if (cur == -1) {
                    cur = sz;
                } else {
                    if (sz != cur) {
                        ok = 0;
                    }
                }
                c += sz;
            }
        }
        if (ok)
            ans++;
        return c;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = (int)edges.size() + 1;
        ans = 0;
        adj.clear();
        adj.resize(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0, -1);
        return ans;
    }
};

// int Solution::countGoodNodes(vector<vector<int>> edges)

int main() {
    cout << "*** 100354. Count the Number of Good Nodes ***" << endl << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3},
                                     {1, 4}, {2, 5}, {2, 6}};
        int ans0 = s0.countGoodNodes(edges);
        int exp0 = 7;

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

        vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4},
                                     {0, 5}, {1, 6}, {2, 7}, {3, 8}};
        int ans1 = s0.countGoodNodes(edges);
        int exp1 = 6;

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
