class Solution {
public:
    bool isValid(int row, int col, vector<int>& v) {
        for (int i = 0; i < row; i++) {
            if (col == v[i]) return false;
            if (col == v[i] + (row - i)) return false;
            if (col == v[i] - (row - i)) return false;
        }
        return true;
    }
    void backtrack(int row, int n, vector<int>& v, int& res) {
        if (row == n) {
            res++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(row, col, v)) {
                v.push_back(col);
                backtrack(row + 1, n, v, res);
                v.pop_back();
            }
        }
    }
    int totalNQueens(int n) {
        int res = 0;
        vector<int> v;
        backtrack(0, n, v, res);
        return res;
    }
};