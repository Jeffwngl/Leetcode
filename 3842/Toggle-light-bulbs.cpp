#include <map>

class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int, int>m;

        for (int i = 0; i < bulbs.size(); i++) {
            m[bulbs[i]] += 1;
        }

        vector<int>result;
        
        for (const auto& [key, value] : m) {
            if (value % 2 != 0) {
                result.push_back(key);
            }
        }
        return result;
    }
};
