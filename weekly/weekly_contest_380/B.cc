// Generated by LeetCodeContestHelper at 5/22/2024, 8:46:05 PM
// 3006. Find Beautiful Indices in the Given Array I
// https://leetcode.com/contest/weekly-contest-380/problems/find-beautiful-indices-in-the-given-array-i/

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

struct Hash {
    const long long mod = (long long)1e9 + 7;
    const long long p = 37;
    vector<long long> pow = {1, 1};
    vector<long long> hashed = {0};

    Hash(string s) {
        long long a = p, b = mod - 2, pm = 1, n = (int)s.size();
        while (b) {
            if (b & 1)
                pm *= a;
            pm %= mod;
            a *= a;
            a %= mod;
            b >>= 1;
        }
        for (int i = 2; i <= n; i++) {
            pow.push_back((pow.back() * pm) % mod);
        }
        long long power = 1;
        for (auto& c : s) {
            hashed.push_back((hashed.back() + (c - 'a' + 1) * power) % mod);
            power = (power * p) % mod;
        }
    }

    long long get(int l, int r) {
        return ((hashed[r] - hashed[l - 1] + mod) % mod) * pow[l] % mod;
    }
};

class Solution {
   public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        Hash hs(s), ha(a), hb(b);
        set<int> st1, st2;
        int sa = (int)a.size(), sb = (int)b.size();
        for (int i = 1; i <= (int)s.size() - sa + 1; i++) {
            if (hs.get(i, i + sa - 1) == ha.get(1, sa)) {
                st1.insert(i);
            }
        }
        vector<int> ans;
        for (int i = 1; i <= (int)s.size() - sb + 1; i++) {
            if (hs.get(i, i + sb - 1) == hb.get(1, sb)) {
                st2.insert(i);
            }
        }
        for (auto e : st1) {
            auto it = st2.lower_bound(e - k);
            if (it != st2.end() && *it <= e + k) {
                ans.push_back(e - 1);
            }
        }
        return ans;
    }
};

// vector<int> Solution::beautifulIndices(string s, string a, string b, int k)

int main() {
    cout << "*** 3006. Find Beautiful Indices in the Given Array I ***" << endl
         << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        string s = "isawsquirrelnearmysquirrelhouseohmy";
        string a = "my";
        string b = "squirrel";
        int k = 15;
        vector<int> ans0 = s0.beautifulIndices(s, a, b, k);
        vector<int> exp0 = {16, 33};

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

        string s = "abcd";
        string a = "a";
        string b = "a";
        int k = 4;
        vector<int> ans1 = s0.beautifulIndices(s, a, b, k);
        vector<int> exp1 = {0};

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
