class Solution {
private:
    vector<vector<int>>res;
    deque<pair<int, int>>dq;
    vector<pair<int, int>>dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>>canFlowPacific;
    vector<vector<int>>canFlowAtlantic;

    void bfs(vector<vector<int>>& heights, vector<vector<int>>& canFlow) {
        int n = heights.size();
        int m = heights[0].size();

        while (!dq.empty()) {
            vector<pair<int, int>>toVisit;
            while (!dq.empty()) {
                toVisit.push_back(dq.front());
                dq.pop_front();
            }

            for (auto const& [r, c] : toVisit) {
                for (auto const& [dx, dy] : dirs) {
                    int new_x = r + dx;
                    int new_y = c + dy;
                    if (new_x < n && new_x >= 0 && 
                        new_y < m && new_y >= 0 && 
                        heights[new_x][new_y] >= heights[r][c] && 
                        canFlow[new_x][new_y] == 0) 
                    {
                        dq.push_back({new_x, new_y});
                        canFlow[new_x][new_y] = 1;
                    }

                }
            }
        }
    };

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        canFlowPacific.resize(n, vector<int>(m, 0));
        canFlowAtlantic.resize(n, vector<int>(m, 0));

        // pacific
        for (int i = 0; i < n; ++i) {
            dq.push_back({i, m - 1});
            canFlowPacific[i][m - 1] = 1;
        }
        for (int i = 0; i < m - 1; ++i) {
            dq.push_back({n - 1, i});
            canFlowPacific[n - 1][i] = 1;
        }

        bfs(heights, canFlowPacific);
        while (!dq.empty()) {
            dq.pop_front();
        }

        // atlantic
        for (int i = 0; i < n; ++i) {
            dq.push_back({i, 0});
            canFlowAtlantic[i][0] = 1;
        }
        for (int i = 1; i < m; ++i) {
            dq.push_back({0, i});
            canFlowAtlantic[0][i] = 1;
        }

        bfs(heights, canFlowAtlantic);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (canFlowPacific[i][j] == 1 && canFlowAtlantic[i][j] == 1) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
