class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();

        vector<int>dpL(n);
        vector<int>dpR(n);

        dpL[0] = 1;
        dpL[1] = 2;

        for (int i = 2; i < n; ++i) {
            if ((nums[i] - nums[i - 1]) == (nums[i - 1] - nums[i - 2])) {
                dpL[i] = dpL[i - 1] + 1;
            }
            else {
                dpL[i] = 2;
            }
        }

        dpR[n - 1] = 1;
        dpR[n - 2] = 2;

        for (int i = n - 3; i >= 0; --i) {
            if ((nums[i + 1] - nums[i]) == (nums[i + 2] - nums[i + 1])) {
                dpR[i] = dpR[i + 1] + 1;
            }
            else {
                dpR[i] = 2;
            }
        }

        int res = 2;

        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                res = max(res, dpL[i - 1] + 1);
            }
            if (i < n - 1) {
                res = max(res, dpR[i + 1] + 1);
            }
            
            if (i == 0) { // take highest cnt from right dp count of numbers
                continue;
            }
            else if (i == n - 1) { // take highest cnt from left dp count of numbers
                res = max(res, dpL[i - 1] + 1);
                continue;
            }
            

            if ((nums[i + 1] - nums[i - 1]) % 2 == 0) {
                
                int validSpace = (nums[i + 1] - nums[i - 1]) / 2;
                int currLeft = 1, currRight = 1;
                
                if (i >= 2 && nums[i - 1] - nums[i - 2] == validSpace) {
                    currLeft = dpL[i - 1];
                }

                if (i < n - 2 && nums[i + 2] - nums[i + 1] == validSpace) {
                    currRight = dpR[i + 1]; // only triggers if both right and left spaces equal to the current validSpace, i.e. we can connect them
                } // otherwise if currLeft OR right = 1, then we just increase the left or right by 1
                // if both are 1, then the answer is 2 which is accounted for before res = 2;
                
                res = max(res, currLeft + currRight + 1);
            }
        }
        return res;
    }
};©leetcode
