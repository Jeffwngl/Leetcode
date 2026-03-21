class Solution {
private:
    vector<vector<int>> dp; // [index][curr_sum] = no. of ways
    int targ = 0;
    int totalSum = 0;
    int res = 0;

    int backTrack(vector<int>&nums, int total, int idx) {
        if (idx >= nums.size()) {
            if (total == targ) return 1;
            return 0;
        }
        if (dp[idx][total + totalSum] != INT_MIN) { // total + totalSum, idx cant be negative, dp[idx][x], x from 0 to 2*totalSum
            return dp[idx][total + totalSum]; // if subproblem has been solved, return answer
        } // e.g. -1, 1, -1 and 1, -1, -1, at idx = 1, both total = 0, instead of going down the recursive
          // call for both cases, we only need to go down one to check, they are both distinct as the start
          // is different but at idx = 1, their total is the same, so the rest of the array can be arranged
          // to make both equal target.

        dp[idx][total + totalSum] = (backTrack(nums, total + nums[idx], idx + 1) + 
                                     backTrack(nums, total - nums[idx], idx + 1));
        return dp[idx][total + totalSum];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        // [-totalSum ... 0 ... +totalSum]
        // INT_MIN = = -2^31
        dp = vector<vector<int>>(nums.size(), vector<int>(2 * totalSum + 1, INT_MIN));
        targ = target;

        return backTrack(nums, 0, 0);
    }
};

//  -5 ... 0 ... 5 totalSum (we will use from 0 .. 10 as we use total + totalSum)
// 0
// 1
// ...
// 5
// index
