class Solution {
private:

    void calcSub(vector<int>& nums, int index, vector<int> current, vector<vector<int>>& res) {
        if (index == nums.size()) {
            res.push_back(current);
            return;
        }

        calcSub(nums, index + 1, current, res);

        current.push_back(nums[index]);
        calcSub(nums, index + 1, current, res);

        current.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>>res;
        vector<int>curr;

        calcSub(nums, 0, curr, res);

        return res;
    }
};
