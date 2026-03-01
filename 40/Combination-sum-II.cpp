class Solution {
private:
    set<vector<int>>res;

    void makeCombination(int idx, vector<int>& curr, vector<int>& candidates, int target) {
        if (target == 0) {
            res.insert(curr);
            return;
        }

        for (int j = idx; j < candidates.size(); j++) {
            if (candidates[j] > target) {
                break;
            }
            if (j > idx && candidates[j] == candidates[j - 1]) {
                continue;
            }
            curr.push_back(candidates[j]);

            makeCombination(j + 1, curr, candidates, target - candidates[j]);

            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        int n = candidates.size();

        vector<int>curr;

        res.clear();
        makeCombination(0, curr, candidates, target);

        vector<vector<int>>ans{res.begin(),res.end()};

        return ans;
    }
};
