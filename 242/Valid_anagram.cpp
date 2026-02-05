#include <algorithm>

class Solution {
public:
    bool isAnagram(string s, string t) {
        int a = s.size();
        int b = t.size();

        if (a != b) {
            return false;
        }

        map<char, int> dictA;
        map<char, int> dictB;

        for (int i = 0; i < a; i++) {
            dictA[s[i]]++;
            dictB[t[i]]++;
        }

        for (auto iterA : dictA) {
            auto iterB = dictB.find(iterA.first);

            if (iterB == dictB.end()) {
                return false;
            }

            if (iterB->second != iterA.second) {
                return false;
            }
        }
        return true;
    }
};
