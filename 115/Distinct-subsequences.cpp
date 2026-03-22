class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (n < m) {
            return 0;
        }

        vector<vector<uint32_t>>dp(n + 1, vector<uint32_t>(m + 1, 0));

        for (size_t i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }

        for (size_t i = 1; i <= n; ++i) {
            for (size_t j = 1; j <= m; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][m];
    }
};
