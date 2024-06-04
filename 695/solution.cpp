class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        int res = 1;
        visited[i][j] = true;
        for (vector<int> dir : dirs) {
            int r = i + dir[0], c = j + dir[1];
            if (r < 0 || r >= m || c < 0 || c >= n) continue;
            if (grid[r][c] == 0) continue;
            if (visited[r][c]) continue;
            res += dfs(grid, r, c, visited);
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    res = max(res, dfs(grid, i, j, visited));
                }
            }
        }
        return res;
    }
};