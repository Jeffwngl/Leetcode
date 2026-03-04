class Solution {
private:
    set<vector<int>>res;
    void makeSubset(int idx, vector<int>&curr, vector<int>&nums) {
        if (idx == nums.size()) {
            res.insert(curr);
            return;
        }

        makeSubset(idx + 1, curr, nums);

        curr.push_back(nums[idx]);

        makeSubset(idx + 1, curr, nums);
        
        curr.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int>curr;
        makeSubset(0, curr, nums);
        vector<vector<int>> newRes(res.begin(), res.end());
        return newRes;
    }
};
