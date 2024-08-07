class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0]) dp[0] = 0;
            for (int j = 1; j < n; j++) {
                dp[j] = obstacleGrid[i][j] ? 0 : dp[j] + dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};