class Solution {
public:
    string maximumXor(string s, string t) {
        int n = s.size();
        int cnt1 = 0;
        int cnt0 = 0;
        for (auto i : t) {
            if (i == '1') {
                cnt1++;
            }
            else {
                cnt0++;
            }
        }

        vector<int>res;
        
        for (auto i : s) {
            if (i == '1') {
                if (cnt0 > 0) {
                    cnt0--;
                    res.push_back(1);
                }
                else {
                    cnt1--;
                    res.push_back(0);
                }
            }
            if (i == '0') {
                if (cnt1 > 0) {
                    cnt1--;
                    res.push_back(1);
                }
                else {
                    cnt0--;
                    res.push_back(0);
                }
            }
        }

        string ans = "";
        int m = res.size();
        for (int i = 0; i < m; ++i) {
            ans += to_string(res[i]);
        }
        return ans;
        
    }
};
