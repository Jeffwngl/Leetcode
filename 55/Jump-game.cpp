class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 0);
        // 1 == true
        // 0 == false
        dp[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] >= n - i - 1) { // base case where it can reach end from i
                dp[i] = 1;
                // cout << "base" << endl;
                continue;
            }
            for (int j = 0; j < nums[i] + 1; ++j) {
                if (dp[i + j] == 1) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        // for (auto const& it : dp) {
        //     cout << it << endl;
        // }
        return dp[0] == 1 ? true : false;
    }
};
