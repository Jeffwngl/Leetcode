class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        vector<int>dp;
        for (int i = 0; i < n; i++) {
            if (i == 0 || i == 1) {
                dp.push_back(cost[i]);
                cout << dp[i] << endl;
                continue;
            }

            dp.push_back(min(dp[i - 1], dp[i - 2]) + cost[i]);
            cout << dp[i] << endl;
        }
        return min(dp[dp.size() - 1], dp[dp.size() - 2]);
    }
};
