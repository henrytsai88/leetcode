class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {
        if (dp[i][j]) return dp[i][j];
        int length = 1;
        for (vector<int> dir : dirs) {
            int r = i + dir[0], c = j + dir[1];
            if (r < 0 || r >= m || c < 0 || c >= n) continue;
            if (matrix[r][c] <= matrix[i][j]) continue;
            length = max(length, 1 + dfs(matrix, r, c, dp));
        }
        if (!dp[i][j]) dp[i][j] = length;
        return length;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dfs(matrix, i, j, dp));
            }
        }
        return res;
    }
};