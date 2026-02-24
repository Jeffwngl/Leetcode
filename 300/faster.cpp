class Solution {
public:
    int binarySearch(int n, vector<int>res) { // returns idx of first element greater than n
        int l = 0;
        int r = res.size() - 1;
        
        while (l <= r) {
            int mid = (l + r) / 2;

            if (res[mid] == n) {
                return mid;
            }
            else if (res[mid] > n) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp;

        for (auto it : nums) {
            if (dp.size() == 0 || dp[dp.size() - 1] < it) {
                dp.push_back(it);
            }
            else {
                int i = binarySearch(it, dp);
                dp[i] = it; // by switching the previous number out, it doesnt change the length of dp
            }               // instead, we switch it out for a smaller value to keep it strictly increasing
        }                   // e.g. 1,2,3,4 is more optimal than 1,2,3,5 in a strictly increasing case

        return dp.size();
    }
};
