class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n, vector<bool>(n));

        int res[] = {0, 0};
        
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
            res[0] = i;
            res[1] = i;
        } // "a"

        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                res[0] = i;
                res[1] = i + 1;
            }
        } // "aa"

        for (int diff = 2; diff < n; ++diff) {
            for (int i = 0; i < n - diff; ++i) {
                int j = i + diff;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    res[0] = i;
                    res[1] = j;
                }
            }
        } // compare all other cases
        
        return s.substr(res[0], res[1] - res[0] + 1);

    }
};
