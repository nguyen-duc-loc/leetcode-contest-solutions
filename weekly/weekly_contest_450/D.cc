// Generated by LeetCodeContestHelper at 5/18/2025, 10:22:34 AM
// 100654. Minimum Weighted Subgraph With the Required Paths II
// https://leetcode.com/contest/weekly-contest-450/problems/minimum-weighted-subgraph-with-the-required-paths-ii/

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

// Performs LCA on a weighted tree

template <class T = int>
struct LCA {  // 0 or 1-indexed, doesn't matter
    int n;
    vector<vector<int>> jump;
    vector<vector<T>> big;
    vector<vector<pair<int, T>>> edges;
    vector<int> depth, tin, tout;
    vector<T> distance;
    int curtime = 0;

    LCA() {}

    LCA(int N) {
        n = N + 1;
        jump = vector<vector<int>>(__lg(n - 1) + 1, vector<int>(n));
        big = vector<vector<T>>(__lg(n - 1) + 1, vector<T>(n));
        edges.resize(n);
        depth.resize(n);
        distance.resize(n);
        tin.resize(n);
        tout.resize(n);
    }

    void add_edge(int a, int b, T c) {
        edges[a].emplace_back(b, c);
        edges[b].emplace_back(a, c);
    }

    void dfs(int cur, int parent = -1, int cur_depth = 0, T cur_dist = 0) {
        tin[cur] = tout[cur] = curtime++;
        depth[cur] = cur_depth;
        distance[cur] = cur_dist;
        jump[0][cur] = parent;
        for (int i = 1; i < jump.size(); i++) {
            if (jump[i - 1][cur] == -1)
                jump[i][cur] = -1;
            else {
                jump[i][cur] = jump[i - 1][jump[i - 1][cur]];
                big[i][cur] =
                    max(big[i - 1][cur], big[i - 1][jump[i - 1][cur]]);
            }
        }
        for (auto [node, w] : edges[cur]) {
            if (node != parent) {
                big[0][node] = w;
                dfs(node, cur, cur_depth + 1, cur_dist + w);
                tout[cur] = curtime++;
            }
        }
    }

    void build(int root = 1) {
        dfs(root);
    }

    pair<int, T> ancestor(int node, int k) {
        // find k-th ancestor of node
        // return [node, max edge weight on path]
        T weight = 0;
        for (int i = 0; i < jump.size(); i++) {
            if (k & (1 << i)) {
                weight = max(weight, big[i][node]);
                node = jump[i][node];
            }
        }
        return make_pair(node, weight);
    }

    pair<int, T> lca(int x, int y) {  // return <lca, max edge on path>
        if (depth[x] < depth[y])
            swap(x, y);
        auto cur = ancestor(x, depth[x] - depth[y]);
        x = cur.first;
        T weight = cur.second;
        if (x == y)
            return make_pair(x, weight);
        for (int i = jump.size() - 1; i >= 0; i--) {
            if (jump[i][x] != jump[i][y]) {
                weight = max(weight, max(big[i][x], big[i][y]));
                x = jump[i][x];
                y = jump[i][y];
            }
        }
        return make_pair(jump[0][x], max(weight, max(big[0][x], big[0][y])));
    }

    T dist(int x, int y) {
        return distance[x] + distance[y] - 2 * distance[lca(x, y).first];
    }

    bool is_ancestor(int x, int y) {
        // Returns whether x is an ancestor of y
        return tin[x] <= tin[y] && tin[y] <= tout[x];
    }

    int find_on_path(int x, int y, int k) {
        // Find the k-th (1-indexed) node on the path from x to y
        // Return -1 if no node exists
        int l = lca(x, y).first;
        int d = depth[x] + depth[y] - 2 * depth[l];
        if (k > d + 1)
            return -1;
        if (depth[x] - depth[l] >= k)
            return ancestor(x, k - 1).first;
        return ancestor(y, d - k + 1).first;
    }

    // Returns a vector of nodes, and a vector of (parent, child) in virtual
    // tree
    pair<vector<int>, vector<pair<int, int>>> virtual_tree(vector<int> nodes) {
        auto&& sort_by_preorder = [&](int a, int b) { return tin[a] < tin[b]; };
        sort(nodes.begin(), nodes.end(), sort_by_preorder);
        int sz = nodes.size();
        for (int i = 0; i + 1 < sz; i++)
            nodes.push_back(lca(nodes[i], nodes[i + 1]).first);
        sort(nodes.begin(), nodes.end(), sort_by_preorder);
        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
        vector<pair<int, int>> res;
        res.reserve(nodes.size() - 1);
        vector<int> st = {nodes[0]};
        for (int i = 1; i < nodes.size(); i++) {
            while (!is_ancestor(st.back(), nodes[i]))
                st.pop_back();
            res.emplace_back(st.back(), nodes[i]);
            st.push_back(nodes[i]);
        }
        return make_pair(nodes, res);
    }
};

class Solution {
   public:
    vector<int> minimumWeight(vector<vector<int>>& edges,
                              vector<vector<int>>& queries) {
        int n = (int)edges.size() + 1;
        LCA<int> tree(n + 5);
        for (auto& e : edges) {
            tree.add_edge(e[0], e[1], e[2]);
        }
        tree.build(0);
        vector<int> ans;
        for (auto& q : queries) {
            int src1 = q[0], src2 = q[1], dest = q[2];
            ans.push_back((tree.dist(src1, src2) + tree.dist(src2, dest) +
                           tree.dist(src1, dest)) /
                          2);
        }
        return ans;
    }
};

// vector<int> Solution::minimumWeight(vector<vector<int>> edges,
// vector<vector<int>> queries)

int main() {
    cout << "*** 100654. Minimum Weighted Subgraph With the Required Paths II "
            "***"
         << endl
         << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        vector<vector<int>> edges = {
            {0, 1, 2}, {1, 2, 3}, {1, 3, 5}, {1, 4, 4}, {2, 5, 6}};
        vector<vector<int>> queries = {{2, 3, 4}, {0, 2, 5}};
        vector<int> ans0 = s0.minimumWeight(edges, queries);
        vector<int> exp0 = {12, 11};

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

        vector<vector<int>> edges = {{1, 0, 8}, {0, 2, 7}};
        vector<vector<int>> queries = {{0, 1, 2}};
        vector<int> ans1 = s0.minimumWeight(edges, queries);
        vector<int> exp1 = {15};

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
