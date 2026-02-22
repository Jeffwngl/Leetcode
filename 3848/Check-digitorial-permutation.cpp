class Solution {
public:
    bool isDigitorialPermutation(int n) {
        string num = to_string(n);
        vector<long long>dp;
        vector<int>v;
        for (char c : num) {
            v.push_back(c - '0');
        }
        sort(v.begin(), v.end());
        
        if (v.size() == 1) {
            int k = n;
            for (int j = k - 1; j > 0; j--) {
                k *= j;
            }
            if (k == n) {
                return true;
            }
            return false;
        }
        // for (auto i : v) {
        //     cout << i << endl;
        // }
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 0) {
                dp.push_back(1);
                continue;
            } 
            if (i == 0) {
                long long b = v[0];
                for (int j = v[0]; j > 0; j--) {
                    b *= j;
                }
                dp.push_back(b);
                // cout << b << endl;
                continue;
            }
            long long c = dp[i - 1];
            // cout << c << endl;
            if (c == 0) {
                c = 1;
            }
            // cout << v[i - 1] << " " << v[i] << endl;
            for (int j = v[i - 1] + 1; j <= v[i]; j++) {
                // cout << j << endl;
                c *= j;
            }
            dp.push_back(c);
        }

        // for (auto i : dp) {
        //     cout << i << endl;
        // }
        
        long long total = accumulate(dp.begin(), dp.end(), 0);
        cout << total << endl;
        string ans = to_string(total);
        
        if (ans.size() != num.size()) {
            return false;
        }
        if (is_permutation(ans.begin(), ans.end(), num.begin())) {
            return true;
        }
        return false;
        // if (n == total) {
        //     return true;
        // }
        // return false;
    }
};
