class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) { 
        map<int, int>m;
        
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] += 1;
        }

        set<int>s;
        vector<int>toRemove;
        
        for (const auto& [key, value] : m) {
            if (s.find(value) != s.end()) {
                toRemove.push_back(value);
                continue;
            }
            s.insert(value);
        }

        for (int i = 0; i < toRemove.size(); i++) {
            if (s.find(toRemove[i]) != s.end()) {
                s.erase(toRemove[i]);
            }
        }

        if (s.size() == 0) {
            return -1;
        }

        set<int>tmp;

        for (const auto& [key, value] : m) {
            if (s.find(value) != s.end()) {
                tmp.insert(key);
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (tmp.find(nums[i]) != tmp.end()) {
                return nums[i];
            }
        }
        
        return -1;
    }
};
