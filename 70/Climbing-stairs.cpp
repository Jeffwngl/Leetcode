class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp;
        if (n == 0) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp.push_back(1);
                continue;
            }
            else if (i == 1) {
                dp.push_back(2);
                continue;
            }
            dp.push_back(dp[i - 1] + dp[i - 2]);
        }
        return dp[n - 1];
    }
};
