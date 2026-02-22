class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp.push_back(nums[0]);
                continue;
            }
            else if (i == 1) {
                dp.push_back(nums[1]);
                continue;
            }
            int prevMax = 0;
            for (int j = dp.size() - 2; j >= 0; j--) {
                prevMax = max(prevMax, dp[j]);
            }
            dp.push_back(prevMax + nums[i]);
        }
        
        int currMax = 0;
        for (int i = 0; i < dp.size(); i++) {
            currMax = max(currMax, dp[i]);
        }
        return currMax;
    }
};

// faster version

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp;
        int n = nums.size();

        if (n == 0) {
            return 0;
        }
        else if (n == 1) {
            return nums[0];
        }

        dp.push_back(nums[0]);
        dp.push_back(max(nums[1], nums[0]));

        for (int i = 2; i < n; i++) {
            dp.push_back(max(dp[i - 1], nums[i] + dp[i - 2]));
        }
        
        return dp[n - 1];
    }
};
