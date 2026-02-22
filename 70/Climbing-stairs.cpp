class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp;
        if (n == 0) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp.push_back(1);
                continue;
            }
            else if (i == 1) {
                dp.push_back(2);
                continue;
            }
            dp.push_back(dp[i - 1] + dp[i - 2]);
        }
        return dp[n - 1];
    }
};

//Editorial
//
//dp[i - 1] represents all possible paths before the current i value that ends in a small hop,
//dp[i - 2] is the same but for a big leap. As these two are physically distinct from eachother
//meaning that all paths in i - 1 is different than all the paths in i - 2, we have to add them
//together.
