class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        int n1 = s1.size();
        int n2 = s2.size();

        if (n1 + n2 != s3.size()) return false;

        /*
        2d dp of whether it is possible to create up to s3[k] with substrings of s1 and s2
        */
        vector<vector<bool>>dp(n1 + 1, vector<bool>(n2 + 1, false)); // s1, s2
        dp[0][0] = true;

        for (size_t i = 1; i <= n1; ++i) {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1]; // true for a sequence of matches, false otherwise
        }
        for (size_t i = 1; i <= n2; ++i) {
            dp[0][i] = dp[0][i - 1] && s2[i - 1] == s3[i - 1];
        }

        for (size_t i = 1; i <= n1; ++i) {
            for (size_t j = 1; j <= n2; ++j) {
                int k = i + j - 1; // equivalent to index_i + index_j + 1
                dp[i][j] = dp[i - 1][j] && s3[k] == s1[i - 1] || dp[i][j - 1] && s3[k] == s2[j - 1];
            }
        }

        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0; j < dp[0].size(); ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return dp[n1][n2];
    }
};
