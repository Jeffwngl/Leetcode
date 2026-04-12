class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int>mp;

        int diff = 0;
        int res = 0;

        mp[0] = -1;

        for (int i = 0; i < n; ++i) {
            diff += nums[i] == 1 ? 1 : -1;

            // if mp[diff] is found again, then in the interval mp[diff] to i, there is an equal 1 and 0
            // a certain diff is only recorded the first time it is seen, therefore gives the max for a diff
            if (mp.find(diff) != mp.end()) {
                res = max(res, i - mp[diff]);
            } 
            else {
                mp[diff] = i;
            }
        }
        return res;
    }
};
