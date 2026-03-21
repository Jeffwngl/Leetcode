class Solution {
private:
    vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    int backTrack(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& matrix) {
        if (dp[i][j] != 0) return dp[i][j];

        int n = matrix.size();
        int m = matrix[0].size();
        int currMaxPath = 1;

        for (auto [dx, dy] : dirs) {
            int new_i = i + dx;
            int new_j = j + dy;
            if (new_i < n && new_i >= 0 && new_j < m && new_j >= 0 && matrix[new_i][new_j] > matrix[i][j]) {
                currMaxPath = max(currMaxPath, 1 + backTrack(new_i, new_j, dp, matrix));
            }
        }

        dp[i][j] = currMaxPath;
        return currMaxPath;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int res = 0;

        vector<vector<int>>dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                res = max(res, backTrack(i, j, dp, matrix));
            }
        }
        return res;
    }
};
