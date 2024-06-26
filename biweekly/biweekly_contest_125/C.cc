// Generated by LeetCodeContestHelper at 4/30/2024, 3:36:36 AM
// 3067. Count Pairs of Connectable Servers in a Weighted Tree Network
// https://leetcode.com/contest/biweekly-contest-125/problems/count-pairs-of-connectable-servers-in-a-weighted-tree-network/

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
    vector<vector<pair<int, int>>> adj;
    int s;

    void dfs(int u, int cur, int parent, int& x) {
        if (cur % s == 0) {
            x++;
        }
        for (auto& e : adj[u]) {
            if (e.first != parent) {
                dfs(e.first, cur + e.second, u, x);
            }
        }
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges,
                                               int signalSpeed) {
        s = signalSpeed;
        int n = (int)edges.size();
        adj.clear();
        adj.resize(n + 1);
        for (auto& e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++) {
            vector<int> v;
            for (auto e : adj[i]) {
                int x = 0;
                dfs(e.first, e.second, i, x);
                v.push_back(x);
            }
            int cnt = 0;
            for (int j = 0; j < (int)v.size() - 1; j++) {
                for (int k = j + 1; k < (int)v.size(); k++) {
                    cnt += v[j] * v[k];
                }
            }
            ans[i] = cnt;
        }
        return ans;
    }
};

// vector<int> Solution::countPairsOfConnectableServers(vector<vector<int>>
// edges, int signalSpeed)

int main() {
    cout << "*** 3067. Count Pairs of Connectable Servers in a Weighted Tree "
            "Network ***"
         << endl
         << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        vector<vector<int>> edges = {
            {0, 1, 1}, {1, 2, 5}, {2, 3, 13}, {3, 4, 9}, {4, 5, 2}};
        int signalSpeed = 1;
        vector<int> ans0 =
            s0.countPairsOfConnectableServers(edges, signalSpeed);
        vector<int> exp0 = {0, 4, 6, 6, 4, 0};

        if (ans0 == exp0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
            cout << "  Answer: ";
            for (int& i : ans0) {
                cout << i << " ";
            }
            cout << endl << "  Expect: ";
            for (int& i : exp0) {
                cout << i << " ";
            }
            cout << endl;
        }
    }

    {
        cout << "Test 2: ";

        vector<vector<int>> edges = {{0, 6, 3}, {6, 5, 3}, {0, 3, 1},
                                     {3, 2, 7}, {3, 1, 6}, {3, 4, 2}};
        int signalSpeed = 3;
        vector<int> ans1 =
            s0.countPairsOfConnectableServers(edges, signalSpeed);
        vector<int> exp1 = {2, 0, 0, 0, 0, 0, 2};

        if (ans1 == exp1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
            cout << "  Answer: ";
            for (int& i : ans1) {
                cout << i << " ";
            }
            cout << endl << "  Expect: ";
            for (int& i : exp1) {
                cout << i << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
