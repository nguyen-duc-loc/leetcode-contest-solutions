// Generated by LeetCodeContestHelper at 5/1/2024, 8:54:04 AM
// 2930. Number of Strings Which Can Be Rearranged to Contain Substring
// https://leetcode.com/contest/biweekly-contest-117/problems/number-of-strings-which-can-be-rearranged-to-contain-substring/

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
    const long long mod = (long long)1e9 + 7;

    long long power(long long a, long long b) {
        if (b == 0)
            return 1LL;
        long long ans = 1;
        while (b) {
            if (b & 1) {
                ans *= a;
                ans %= mod;
            }
            a *= a;
            a %= mod;
            b >>= 1;
        }
        return ans;
    }

    int stringCount(int n) {
        long long all = power(26, n);
        long long a = power(25, n);
        long long b = a;
        long long c = (power(25, n) + (n * power(25, n - 1)) % mod) % mod;
        long long ab = power(24, n);
        long long ac = (power(24, n) + (n * power(24, n - 1)) % mod) % mod;
        long long bc = ac;
        long long abc = (power(23, n) + (n * power(23, n - 1)) % mod) % mod;
        return (all + mod - (a + b + c - ab - ac - bc + abc + mod) % mod) % mod;
    }
};

// int Solution::stringCount(int n)

int main() {
    cout << "*** 2930. Number of Strings Which Can Be Rearranged to Contain "
            "Substring ***"
         << endl
         << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        int n = 4;
        int ans0 = s0.stringCount(n);
        int exp0 = 12;

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

        int n = 10;
        int ans1 = s0.stringCount(n);
        int exp1 = 83943898;

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
