class Solution {
private:
    int res = 0;
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void bfs(int i, int j, vector<vector<char>>& grid) {
        deque<pair<int, int>> dq;
        grid[i][j] = '0';
        dq.push_back({i, j});

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();
            for (auto const& [dx, dy] : dirs) {
                if (r + dx >= 0 && r + dx < grid.size() && 
                    c + dy >= 0 && c + dy < grid[0].size() &&
                    grid[r + dx][c + dy] == '1') 
                {
                    dq.push_back({r + dx, c + dy});
                    grid[r + dx][c + dy] = 0;
                }
            }
        }
        res++;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 1 && grid[0].size() == 1) {
            return grid[0][0] == '1' ? 1 : 0;
        }

        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    bfs(i, j, grid);
                }
            }
        }
        return res;
    }
};
