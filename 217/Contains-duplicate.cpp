class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> seen;
        for (int i = 0; i < nums.size(); i++) {
            if (seen.contains(nums[i])) {
                return true;
            }
            seen.insert(nums[i]);
        }
        return false;
    }
};
