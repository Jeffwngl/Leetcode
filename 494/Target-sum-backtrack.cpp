class Solution {
private:
    int targ = 0;
    int backTrack(vector<int>&nums, int currSum, int idx) {
        if (idx >= nums.size()) {
            if (currSum == targ) {
                return 1;
            }
            return 0;
        }

        return (backTrack(nums, currSum + nums[idx], idx + 1) + 
                backTrack(nums, currSum - nums[idx], idx + 1));
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        targ = target;

        return backTrack(nums, 0, 0);
    }
};
