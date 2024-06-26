// Generated by LeetCodeContestHelper at 5/26/2024, 9:33:21 AM
// 100326. String Compression III
// https://leetcode.com/contest/weekly-contest-399/problems/string-compression-iii/

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
    string compressedString(string word) {
        char c = '0';
        int cnt = 0;
        string ans;
        for (auto& e : word) {
            if (e != c || cnt == 9) {
                if (cnt) {
                    ans += to_string(cnt);
                    ans.push_back(c);
                }
                cnt = 1;
                c = e;
            } else {
                cnt++;
            }
        }
        ans += to_string(cnt);
        ans.push_back(c);
        return ans;
    }
};

// string Solution::compressedString(string word)

int main() {
    cout << "*** 100326. String Compression III ***" << endl << endl;

    Solution s0;

    {
        cout << "Test 1: ";

        string word = "abcde";
        string ans0 = s0.compressedString(word);
        string exp0 = "1a1b1c1d1e";

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

        string word = "aaaaaaaaaaaaaabb";
        string ans1 = s0.compressedString(word);
        string exp1 = "9a5a2b";

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
