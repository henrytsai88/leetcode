class Solution {
public:
    bool search(vector<vector<char>>& board, string& word, int i, int j, int count) {
        int m = board.size(), n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        if (board[i][j] != word[count++]) return false;
        if (count == word.size()) return true;
        board[i][j] ^= 128;
        bool res = search(board, word, i - 1, j, count) ||
            search(board, word, i + 1, j, count) ||
            search(board, word, i, j - 1, count) ||
            search(board, word, i, j + 1, count);
        board[i][j] ^= 128;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (search(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};