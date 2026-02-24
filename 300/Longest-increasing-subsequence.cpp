class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return 1;
        }

        vector<int>dp;

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp.push_back(1);
                continue;
            }

            int currMax = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    currMax = max(currMax, dp[j]);
                } 
            }
            if (currMax == 0) {
                dp.push_back(1);
            }
            else {
                dp.push_back(currMax + 1);
            }
        }

        for (auto it : dp) {
            cout << it << endl;
        }
        
        vector<int>::iterator maxVal = max_element(dp.begin(), dp.end());

        return *maxVal;
    }
};
