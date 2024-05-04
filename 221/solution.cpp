class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), maxSide = 0;
        vector<int> pre(n, 0), cur(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    cur[j] = matrix[i][j] - '0';
                }
                else if (matrix[i][j] == '1') {
                    cur[j] = min(min(pre[j], pre[j - 1]), cur[j - 1]) + 1;
                }
                maxSide = max(maxSide, cur[j]);
            }
            fill(pre.begin(), pre.end(), 0);
            swap(pre, cur);
        }
        return maxSide * maxSide;
    }
};