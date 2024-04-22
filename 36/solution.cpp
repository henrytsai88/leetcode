class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool visited[9][9] = {0}, visited2[9][9] = {0}, visited3[9][9] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '1', k = i / 3 * 3 + j / 3;
                if (visited[i][num] || visited2[j][num] || visited3[k][num]) return false;
                visited[i][num] = visited2[j][num] = visited3[k][num] = true;
            }
        }
        return true;
    }
};