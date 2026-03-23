class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        if (n == 0 || m == 0) {
            return max(n, m);
        }

        vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));

        int cnt = 0;
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = cnt;
            cnt++;
        }

        cnt = 0;
        for (int i = 0; i <= m; ++i) {
            dp[0][i] = cnt;
            cnt++;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(1 + dp[i][j - 1], min(1 + dp[i - 1][j], 1 + dp[i - 1][j - 1]));
                }
            }
        }
        return dp[n][m];
    }
};

// for instance, word1 = "horse" and word2 = "ros"
// at i = 3 and j = 3, we have "hor" and "ros",
// for the delete case, we use i - 1 and j to get "ho" and "ros",
// dp[i - 1][j] represents the minimum cost to get "ho" to "ros",
// then we add 1 to delete "r" from "hor" to get closer to "ros"
// similar case for insert
