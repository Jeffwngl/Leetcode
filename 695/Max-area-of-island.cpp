class Solution {
private:
    vector<pair<int, int>>dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int res = 0;
    int n, m;

    int bfs(int i, int j, vector<vector<int>>& grid) {
        deque<pair<int, int>>dq;
        grid[i][j] = 0;
        dq.push_back({i, j});
        int area = 1;

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();
            for (auto const& [dx, dy] : dirs) {
                int new_x = r + dx;
                int new_y = c + dy;
                // cout << new_x << endl;

                if (new_x < n && new_x >= 0 && 
                    new_y < m && new_y >= 0 && 
                    grid[new_x][new_y] == 1) 
                {   
                    dq.push_back({new_x, new_y});
                    grid[new_x][new_y] = 0;
                    area++;
                }
            }   
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> copy = grid;
        
        if (n == 1 && m == 1) {
            return grid[0][0] == 1 ? 1 : 0;
        }

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    res = max(res, bfs(i, j, grid));
                }
            }
        }

        return res;
    }
};
