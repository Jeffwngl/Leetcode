class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }

        vector<vector<bool>> dp(n, vector<bool>(n));

        int res = 0;
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            res++;
        }

        for (int i = 0; i < n - 1; i++) {
            int j = i + 1;
            if (s[i] == s[j]) {
                dp[i][j] = true;
                res++;
            }
        }

        for (int diff = 2; diff < n; diff++) {
            for (int i = 0; i < n - diff; i++) {
                int j = i + diff;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    res++;
                }
            }
        }
        return res;
    }
};
