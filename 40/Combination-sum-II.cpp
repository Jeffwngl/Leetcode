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

//Visualization with [1, 1, 1, 2], Target 3
//
//Slot 1: You pick the first 1.
//
//    Slot 2: You pick the second 1.
//
//        Slot 3: You pick the third 1. Result: [1, 1, 1] (Target reached!).
//
//Backtrack to Slot 2: You just finished with the second 1. The loop moves to the third 1.
//
//    TRIGGER: j > idx (2>1) and candidates[2] == candidates[1].
//
//    Result: Skip! Because [1, 1, ...] was already handled by the previous branch.
//
//Backtrack to Slot 1: You just finished everything starting with the first 1. The loop moves to the second 1.
//
//        TRIGGER: j > idx (1>0) and candidates[1] == candidates[0].
//
//        Result: Skip! Because [1, ...] was already handled when we picked the first 1.
