class Solution {
private:
    vector<vector<int>>res;
    void makeCombination(vector<int>& candidates, int remaining, vector<int>curr, int idx) {
        if (remaining == 0) {
            res.push_back(curr);
            return;
        }
        if (idx >= candidates.size() || remaining < 0) {
            return;
        }

        curr.push_back(candidates[idx]);

        makeCombination(candidates, remaining - candidates[idx], curr, idx);

        curr.pop_back();
 
        makeCombination(candidates, remaining, curr, idx + 1);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;

        int n = candidates.size();
        sort(candidates.begin(), candidates.end());

        makeCombination(candidates, target, curr, 0);

        return res;
    }
};

// This method first sorts the original array and the uses the difference between the current sum of the curr array and the target number
// We dont need to use accumulate here
