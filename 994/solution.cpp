class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), minute = 0, fresh = 0;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) fresh++;
                if (grid[i][j] == 2) q.push({i, j});
            }
        }
        while (true) {
            int size = q.size();
            while (size--) {
                pair<int, int> p = q.front(); q.pop();
                for (vector<int> dir : dirs) {
                    int i = p.first + dir[0], j = p.second + dir[1];
                    if (i < 0 || i >= m || j < 0 || j >= n) continue;
                    if (grid[i][j] == 1) {
                        grid[i][j] = 2;
                        q.push({i, j});
                        fresh--;
                    }
                }
            }
            if (q.empty()) break;
            minute++;
        }
        return fresh == 0 ? minute : -1;
    }
};