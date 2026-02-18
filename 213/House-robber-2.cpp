class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0) {
            return 0;
        }
        else if (n == 1) {
            return nums[0];
        }
        else if (n == 2) {
            return max(nums[1], nums[0]);
        }

        vector<int>dp1;
        dp1.push_back(nums[0]);
        dp1.push_back(max(nums[0], nums[1]));

        for (int i = 2; i < n - 1; i++) {
            dp1.push_back(max(dp1[i - 1], dp1[i - 2] + nums[i]));
        }

        vector<int>dp2;
        dp2.push_back(nums[n - 1]);
        dp2.push_back(max(nums[n - 1], nums[n - 2]));

        int j = 2;
        for (int i = n - 3; i > 0; i--) {
            dp2.push_back(max(dp2[j - 1], dp2[j - 2] + nums[i]));
            j++;
        }

        return max(dp1[dp1.size() - 1], dp2[dp2.size() - 1]);
    }
};
