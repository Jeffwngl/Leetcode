class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n + 1); // index, [curr_sum][count]
        dp[0][0] = 1;

        for (size_t i = 0; i < n; ++i) {
            for (auto &p : dp[i]) {
                dp[i + 1][p.first + nums[i]] += p.second;
                dp[i + 1][p.first - nums[i]] += p.second;
            }
        }
        return dp[n][target];
    }
};

//         -5 -4 -3 -2 -1  0  1  2  3  4  5
// dp[0]:   0  0  0  0  0  1  0  0  0  0  0

// dp[1]:   0  0  0  0  1  0  1  0  0  0  0

// dp[2]:   0  0  0  1  0  2  0  1  0  0  0

// dp[3]:   0  0  1  0  3  0  3  0  1  0  0

// dp[4]:   0  1  0  4  0  6  0  4  0  1  0

// dp[5]:   1  0  5  0 10  0 10  0  5  0  1

