class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({-grid[0][0], {0, 0}});
        while (true) {
            auto cur = pq.top(); pq.pop();
            int height = -cur.first, i = cur.second.first, j = cur.second.second;
            res = max(res, height);
            visited[i][j] = true;
            if (i == n - 1 && j == n - 1) return res;
            for (vector<int>& dir : dirs) {
                int r = i + dir[0], c = j + dir[1];
                if (r < 0 || r >= n || c < 0 || c >= n) continue;
                if (visited[r][c]) continue;
                pq.push({-grid[r][c], {r, c}});
            }
        }
        return -1;
    }
};