class Solution {
private:
    vector<vector<string>>res;
    vector<pair<int,int>> dirs = {
        {0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}
    };

    void placeNewQueen(vector<vector<int>>& cells, int x, int y) {
        int n = cells.size();
        cells[x][y] = 1;
        for (auto [dx, dy] : dirs) {
            int new_x = x + dx;
            int new_y = y + dy;
            while (new_x < n && new_x >= 0 && new_y < n && new_y >= 0) {
                cells[new_x][new_y] = 1;
                new_x += dx;
                new_y += dy;
            }
        }
    };

    void findQueen(
        string currRow, 
        int row,
        vector<string> currCase,
        vector<vector<int>>& validCells
        ) {
        int n = currRow.size();
        if (row == n) {
            res.push_back(currCase);
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            if (validCells[row][col] != 1) {
                currCase[row][col] = 'Q';
                vector<vector<int>> prev = validCells;
                placeNewQueen(validCells, row, col);

                findQueen(currRow, row + 1, currCase, validCells);

                currCase[row][col] = '.';
                validCells = prev;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> validCells(n, vector<int>(n));
        vector<string> currCase(n, string(n, '.'));
        string currRow(n, '.');
        findQueen(currRow, 0, currCase, validCells);
        return res;
    }
};
