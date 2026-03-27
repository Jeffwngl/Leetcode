class Solution {
private:
    vector<pair<int, int>>dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int res = 0;
    deque<pair<int, int>>dq;

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (m == 0 && n == 0) {
            return 0;
        }

        vector<pair<int, int>>rotten;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    rotten.push_back({i, j});
                }
            }
        }

        for (size_t i = 0; i < rotten.size(); ++i) {
            dq.push_back(rotten[i]);
        }
        int time = 0;
        while (!dq.empty()) {
            vector<pair<int, int>>toVisit;
            while(!dq.empty()) {
                auto [r, c] = dq.front();
                toVisit.push_back({r, c});
                dq.pop_front();
            }

            for (auto& [r, c] : toVisit) {
                for (auto const& [dx, dy] : dirs) {
                    int new_x = r + dx;
                    int new_y = c + dy;

                    if (new_x < n && new_x >= 0 && 
                        new_y < m && new_y >= 0 && 
                        grid[new_x][new_y] == 1) 
                    {   
                        grid[new_x][new_y] = 2;
                        dq.push_back({new_x, new_y});
                    }
                }
            }
            if (!dq.empty()) {
                time++;
            }
        }

        int leftOver = 0;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    leftOver++;
                }
            }
        }

        if (leftOver > 0) {
            return -1;
        }

        return time;
    }
};
