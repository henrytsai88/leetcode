class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<char>>& board, int i, int j) {
        board[i][j] = '#';
        for (vector<int> dir : dirs) {
            int r = i + dir[0], c = j + dir[1];
            if (r < 0 || r >= m || c < 0 || c >= n) continue;
            if (board[r][c] == 'X' || board[r][c] == '#') continue;
            dfs(board, r, c);
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][n - 1] == 'O') dfs(board, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[m - 1][j] == 'O') dfs(board, m - 1, j);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};