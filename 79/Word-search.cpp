class Solution {
private:
    bool res = false;

    vector<pair<int, int>> dirs = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    void checkExists(int i, int j, int currIndex, vector<vector<char>>& board, string& word, vector<vector<int>>& visited) {
        if (res) {
            return;
        }
        if (board[i][j] != word[currIndex]) {
            return;
        }
        if (visited[i][j] == 1) {
            return;
        }
        if (currIndex == word.size() - 1) {
            if (word[currIndex] == board[i][j]) {
                res = true;
            }
            return;
        }

        for (auto [dx, dy] : dirs) {
            int neighbourI = i + dx;
            int neighbourJ = j + dy;

            if (neighbourI < 0 || 
                neighbourJ < 0 ||
                neighbourI > board.size() - 1 || 
                neighbourJ > board[0].size() - 1
                ) {
                 continue;
            }
            
            // string t(curr.begin(), curr.end());
            // cout << t << endl;
            visited[i][j] = 1;
            checkExists(neighbourI, neighbourJ, currIndex + 1, board, word, visited);
            visited[i][j] = 0;
        }
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                vector<vector<int>>visited(n, vector<int>(m, 0));
                checkExists(i, j, 0, board, word, visited);
            }
        }

        return res;
    };
};
