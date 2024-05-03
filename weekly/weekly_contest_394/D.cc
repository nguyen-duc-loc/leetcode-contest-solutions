// Generated by LeetCodeContestHelper at 4/30/2024, 3:33:47 AM
// 3123. Find Edges in Shortest Paths
// https://leetcode.com/contest/weekly-contest-394/problems/find-edges-in-shortest-paths/

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

template <class T>
struct edge {
    int node;
    T weight;

    edge() {}

    edge(int _node, T _weight) : node(_node), weight(_weight) {}
};

template <class T, bool directed = true>
struct dijkstra {  // 0 or 1-indexed, doesn't matter
    int n;
    vector<vector<edge<T>>> edges;
    const T INF = numeric_limits<T>::max() / 2;

    dijkstra() {}

    dijkstra(int N) {
        n = N;
        edges.resize(n + 1);
    }

    void add_edge(int from, int to, T dist) {
        edges[from].emplace_back(to, dist);
        if (!directed)
            edges[to].emplace_back(from, dist);
    }

    vector<T> dist(vector<int> sources) {
        vector<T> res(n + 1, INF);
        priority_queue<pair<T, int>, vector<pair<T, int>>,
                       greater<pair<T, int>>>
            pq;
        for (int source : sources) {
            res[source] = 0;
            pq.push({0, source});
        }
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if (cur.first > res[cur.second])
                continue;
            for (auto e : edges[cur.second]) {
                if (res[e.node] > cur.first + e.weight) {
                    res[e.node] = cur.first + e.weight;
                    pq.push({res[e.node], e.node});
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            if (res[i] == INF)
                res[i] = -1;
        }
        return res;
    }

    T dist(int source, int dest) {
        return dist({source})[dest];
    }

    pair<T, vector<int>> path(int source, int dest) {
        // Return the distance from source to dest, along with a shortest path
        vector<T> res(n + 1, INF);
        vector<int> before(n + 1);
        priority_queue<pair<T, int>, vector<pair<T, int>>,
                       greater<pair<T, int>>>
            pq;
        res[source] = 0;
        pq.push({0, source});
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if (cur.first > res[cur.second])
                continue;
            for (auto e : edges[cur.second]) {
                if (res[e.node] > cur.first + e.weight) {
                    res[e.node] = cur.first + e.weight;
                    before[e.node] = cur.second;
                    pq.push({res[e.node], e.node});
                }
            }
        }
        if (res[dest] == INF)
            return make_pair(-1, vector<int>());
        vector<int> path = {dest};
        while (path.back() != source)
            path.push_back(before[path.back()]);
        reverse(path.begin(), path.end());
        return make_pair(res[dest], path);
    }
};

class Solution {
   public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        dijkstra<long long, false> graph(n);
        int sz = (int)edges.size();
        vector<bool> ans(sz);
        for (auto& e : edges) {
            graph.add_edge(e[0], e[1], 1LL * e[2]);
        }
        auto shortest = graph.dist(0, n - 1);
        if (shortest == -1) {
            return ans;
        }
        auto v1 = graph.dist({0});
        auto v2 = graph.dist({n - 1});
        for (int i = 0; i < sz; i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            auto d1 = v1[from];
            auto d2 = v2[to];
            if (d1 == -1 || d2 == -1) {
                continue;
            }
            if (d1 + d2 + 1LL * edges[i][2] == shortest) {
                ans[i] = 1;
            }
            d1 = v1[to];
            d2 = v2[from];
            if (d1 == -1 || d2 == -1) {
                continue;
            }
            if (d1 + d2 + 1LL * edges[i][2] == shortest) {
                ans[i] = 1;
            }
        }
        return ans;
    }
};

// vector<bool> Solution::findAnswer(int n, vector<vector<int>> edges)

int main() {
    cout << "*** 3123. Find Edges in Shortest Paths ***" << endl << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        int n = 6;
        vector<vector<int>> edges = {{0, 1, 4}, {0, 2, 1}, {1, 3, 2},
                                     {1, 4, 3}, {1, 5, 1}, {2, 3, 1},
                                     {3, 5, 3}, {4, 5, 2}};
        vector<bool> ans0 = s0.findAnswer(n, edges);
        vector<bool> exp0 = {true, true, true, false, true, true, true, false};

        if (ans0 == exp0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
            cout << "  Answer: ";
            for (bool i : ans0) {
                cout << i << " ";
            }
            cout << endl << "  Expect: ";
            for (bool i : exp0) {
                cout << i << " ";
            }
            cout << endl;
        }
    }

    {
        cout << "Test 2: ";

        int n = 4;
        vector<vector<int>> edges = {
            {2, 0, 1}, {0, 1, 1}, {0, 3, 4}, {3, 2, 2}};
        vector<bool> ans1 = s0.findAnswer(n, edges);
        vector<bool> exp1 = {true, false, false, true};

        if (ans1 == exp1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
            cout << "  Answer: ";
            for (bool i : ans1) {
                cout << i << " ";
            }
            cout << endl << "  Expect: ";
            for (bool i : exp1) {
                cout << i << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
