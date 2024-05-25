// Generated by LeetCodeContestHelper at 5/25/2024, 9:37:34 PM
// 100313. Find the Number of Distinct Colors Among the Balls
// https://leetcode.com/contest/biweekly-contest-131/problems/find-the-number-of-distinct-colors-among-the-balls/

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
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        for (auto& e : queries) {
            if (mp1.count(e[0])) {
                auto c = mp1[e[0]];
                if (!(--mp2[c])) {
                    mp2.erase(c);
                }
            }
            mp1[e[0]] = e[1];
            mp2[e[1]]++;
            ans.push_back((int)mp2.size());
        }
        return ans;
    }
};

// vector<int> Solution::queryResults(int limit, vector<vector<int>> queries)

int main() {
    cout << "*** 100313. Find the Number of Distinct Colors Among the Balls ***"
         << endl
         << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        int limit = 4;
        vector<vector<int>> queries = {{1, 4}, {2, 5}, {1, 3}, {3, 4}};
        vector<int> ans0 = s0.queryResults(limit, queries);
        vector<int> exp0 = {1, 2, 2, 3};

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

        int limit = 4;
        vector<vector<int>> queries = {{0, 1}, {1, 2}, {2, 2}, {3, 4}, {4, 5}};
        vector<int> ans1 = s0.queryResults(limit, queries);
        vector<int> exp1 = {1, 2, 2, 3, 4};

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
