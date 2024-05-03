class Solution {
   public:
    int minimumDeletions(string word, int k) {
        vector<int> v;
        for (char c = 'a'; c <= 'z'; c++) {
            int t = count(word.begin(), word.end(), c);
            if (t > 0) {
                v.push_back(t);
            }
        }
        int ans = INT_MAX;
        for (auto& e : v) {
            int c = 0;
            for (auto& x : v) {
                if (x < e)
                    c += x;
                else
                    c += max(0, x - e - k);
            }
            ans = min(ans, c);
        }
        return ans;
    }
};