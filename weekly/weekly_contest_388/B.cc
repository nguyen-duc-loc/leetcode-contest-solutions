// Generated by LeetCodeContestHelper at 4/30/2024, 3:23:38 AM
// 3075. Maximize Happiness of Selected Children
// https://leetcode.com/contest/weekly-contest-388/problems/maximize-happiness-of-selected-children/

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
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> q;
        int cur = 0;
        long long ans = 0;
        for (auto& e : happiness) {
            q.push(e);
        }
        while (k--) {
            auto t = q.top();
            q.pop();
            if (t - cur > 0) {
                ans += 1LL * (t - cur);
            }
            cur++;
        }
        return ans;
    }
};

// long long Solution::maximumHappinessSum(vector<int> happiness, int k)

int main() {
    cout << "*** 3075. Maximize Happiness of Selected Children ***" << endl
         << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        vector<int> happiness = {1, 2, 3};
        int k = 2;
        long long ans0 = s0.maximumHappinessSum(happiness, k);
        long long exp0 = 4;

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

        vector<int> happiness = {1, 1, 1, 1};
        int k = 2;
        long long ans1 = s0.maximumHappinessSum(happiness, k);
        long long exp1 = 1;

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

        vector<int> happiness = {2, 3, 4, 5};
        int k = 1;
        long long ans2 = s0.maximumHappinessSum(happiness, k);
        long long exp2 = 5;

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
