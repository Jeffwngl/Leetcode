class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        map<string, vector<string>>m;
        for (int i = 0; i < n; i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            m[s].push_back(strs[i]);
        }

        vector<vector<string>>res;

        for (const auto& [key, value] : m) {
            res.push_back(value);
        }

        return res;
    }
};
