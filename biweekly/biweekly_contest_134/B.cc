// Generated by LeetCodeContestHelper at 7/8/2024, 11:23:14 AM
// 3207. Maximum Points After Enemy Battles
// https://leetcode.com/contest/biweekly-contest-134/problems/maximum-points-after-enemy-battles/

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
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        ranges::sort(enemyEnergies);
        if (currentEnergy < enemyEnergies.front()) {
            return 0;
        }
        long long t = currentEnergy - enemyEnergies.front();
        for (int i = 1; i < (int)enemyEnergies.size(); i++) {
            t += enemyEnergies[i];
        }
        return 1 + t / enemyEnergies.front();
    }
};

// long long Solution::maximumPoints(vector<int> enemyEnergies, int
// currentEnergy)

int main() {
    cout << "*** 3207. Maximum Points After Enemy Battles ***" << endl << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        vector<int> enemyEnergies = {3, 2, 2};
        int currentEnergy = 2;
        long long ans0 = s0.maximumPoints(enemyEnergies, currentEnergy);
        long long exp0 = 3;

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

        vector<int> enemyEnergies = {2};
        int currentEnergy = 10;
        long long ans1 = s0.maximumPoints(enemyEnergies, currentEnergy);
        long long exp1 = 5;

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
