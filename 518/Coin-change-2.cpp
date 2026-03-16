class Solution {
public:
    int change(int amount, vector<int>& coins) {
         int n = coins.size();

         vector<vector<unsigned int>>dp(n + 1, vector<unsigned int>(amount + 1));

        // 2d dp array, where dp[i][j] is the no. of combinations we can sum with coins of i and j
        // dp[i - 1][j], number of ways to make j without current coin
        // dp[i][j - coins[i - 1]], number of ways to make j - coins[i - 1] (all prev coins) 
        // and then with current the coin on top
        for (size_t i = 0; i < n; ++i) { dp[i][0] = 1; }

        for (size_t i = 1; i <= n; ++i) {
            for (size_t j = 0; j <= amount; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1]) {
                    dp[i][j] += dp[i][j - coins[i - 1]]; // no. of ways using coins[i] to make j - coins[i - 1]
                } // we already acounted for making j using coins[i - 1] so we dont count that in above
            }
         }
         return dp[n][amount];

    }
};
