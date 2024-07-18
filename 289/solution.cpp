class Solution {
public:
    int m, n;
    int countNeighbor(vector<vector<int>>& board, int i, int j) {
        int res = 0;
        for (int r = max(i - 1, 0); r <= min(i + 1, m - 1); r++) {
            for (int c = max(j - 1, 0); c <= min(j + 1, n - 1); c++) {
                res += board[r][c] & 1;
            }
        }
        return res;
    }
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int count = countNeighbor(board, i, j);
                if (board[i][j] == 1) {
                    if (count == 3 || count == 4) board[i][j] = 0b11;
                    else board[i][j] = 0b01;
                }
                else {
                    if (count == 3) board[i][j] = 0b10;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] >>= 1;
            }
        }
    }
};