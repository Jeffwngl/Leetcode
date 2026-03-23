class Solution {
private:
    int getCost(vector<int>& balloons, int idx, int l, int r) {
        return balloons[idx] * balloons[l] * balloons[r];
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> balloons(n + 2, 1);

        for (int i = 1; i <= n; ++i) {
            balloons[i] = nums[i - 1];
        }
        
        vector<vector<int>>dp(n + 2, vector<int>(n + 2, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n - i + 1; ++j) {
                int l = j, r = j + i - 1;
                if (l == r) {
                    dp[l][r] = getCost(balloons, l, l - 1, l + 1);
                }
                else if (l > r) {
                    dp[l][r] = 0;
                }
                else {
                    int maxCost = 0;
                    for (int k = l; k <= r; ++k) {
                        maxCost = max(getCost(balloons, k, l - 1, r + 1) + dp[l][k - 1] + dp[k + 1][r], maxCost);
                    }
                    dp[l][r] = maxCost;
                }
            }
        }
        return dp[1][n];
    }
};

// k is the last balloon to burst in the range of i to j, by choosing different values of k
// we can see what order in the interval gives the max coins
