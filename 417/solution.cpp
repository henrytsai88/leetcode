class Solution {
public:
    int m, n;
    void search(vector<vector<int>>& heights, int i, int j, int height, vector<vector<bool>>& matrix) {
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (matrix[i][j] || heights[i][j] < height) return;
        matrix[i][j] = true;
        search(heights, i - 1, j, heights[i][j], matrix);
        search(heights, i + 1, j, heights[i][j], matrix);
        search(heights, i, j - 1, heights[i][j], matrix);
        search(heights, i, j + 1, heights[i][j], matrix);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) search(heights, i, 0, 0, pacific);
        for (int j = 0; j < n; j++) search(heights, 0, j, 0, pacific);
        for (int i = 0; i < m; i++) search(heights, i, n - 1, 0, atlantic);
        for (int j = 0; j < n; j++) search(heights, m - 1, j, 0, atlantic);
        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
};