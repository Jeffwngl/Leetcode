class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int>m;
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }

        vector<int>res;
        while (k > 0) {
            int max_v = 0;
            int max_k = 0;
            for (const auto& [key,value] : m) {
                if (value > max_v) {
                    max_v = value;
                    max_k = key;
                }
            }
            m.erase(max_k);
            res.push_back(max_k);
            k--;
        }
        return res;
    }
};
