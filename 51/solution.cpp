class Solution {
public:
    vector<vector<string>> res;
    vector<string> board;
    bool isValid(int row, int col, int n) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
            if (col - (row - i) >= 0 && board[i][col - (row - i)] == 'Q') return false;
            if (col + (row - i) < n && board[i][col + (row - i)] == 'Q') return false;
        }
        return true;
    }
    void backtrack(int row, int n) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(row, col, n)) {
                board[row][col] = 'Q';
                backtrack(row + 1, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        for (int i = 0; i < n; i++) board.push_back(string(n, '.'));
        backtrack(0, n);
        return res;
    }
};