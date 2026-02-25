class Solution {
private:
    vector<vector<int>>res;
    void makeCombination(vector<int>& candidates, int target, vector<int>curr, int idx) {
        int t = accumulate(curr.begin(), curr.end(), 0);
        if (t == target) {
            res.push_back(curr);
            return;
        }
        if (idx >= candidates.size()) {
            return;
        }
        if (t > target) {
            return;
        }

        curr.push_back(candidates[idx]);

        makeCombination(candidates, target, curr, idx);

        curr.pop_back();

        if (idx + 1 <= candidates.size() - 1) {
            makeCombination(candidates, target, curr, idx + 1);
        }
        
        curr.pop_back();
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;

        int n = candidates.size();

        makeCombination(candidates, target, curr, 0);

        return res;
    }
};
