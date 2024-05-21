class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c) return false;
            if (board[i][col] == c) return false;
            if (board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == c) return false;
        }
        return true;
    }
    bool backtrack(vector<vector<char>>& board, int index) {
        if (index == 81) return true;
        int i = index / 9, j = index % 9;
        if (board[i][j] == '.') {
            for (char c = '1'; c <= '9'; c++) {
                if (isValid(board, i, j, c)) {
                    board[i][j] = c;
                    if (backtrack(board, index + 1)) return true;
                    board[i][j] = '.';
                }
            }
            return false;
        }
        else return backtrack(board, index + 1);
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0);
    }
};