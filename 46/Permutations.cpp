class Solution {
private:
    vector<vector<int>>res;

    void makePermutation(vector<int>&nums, vector<int>&curr, set<int>visited) {
        if (nums.size() == curr.size()) {
            res.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited.find(nums[i]) != visited.end()) {
                continue;
            }

            curr.push_back(nums[i]);

            visited.insert(nums[i]);

            makePermutation(nums, curr, visited);

            int remove = curr[curr.size() - 1];
            curr.pop_back();

            visited.erase(remove);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        set<int>visited;
        vector<int>curr;
        int n = nums.size();
        
        makePermutation(nums, curr, visited);

        return res;
    }
};
