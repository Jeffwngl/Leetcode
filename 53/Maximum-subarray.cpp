class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>dp;
        dp.push_back(nums[0]);

        int currMax = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            dp.push_back(max(dp[i - 1] + nums[i], nums[i]));
            currMax = max(dp[i], currMax);
        }

        return currMax;
    }
};
