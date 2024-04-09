class Solution {
public:
    void fill(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        if (grid[i][j] == '0') return;
        grid[i][j] = '0';
        fill(grid, i - 1, j);
        fill(grid, i + 1, j);
        fill(grid, i, j - 1);
        fill(grid, i, j + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    fill(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};