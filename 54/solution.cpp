class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), i = 0, j = -1, dir = 0;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> res;
        while (m && n) {
            int count = dir % 2 == 0 ? n : m;
            while (count--) {
                i += dirs[dir][0];
                j += dirs[dir][1];
                res.push_back(matrix[i][j]);
            }
            dir % 2 == 0 ? m-- : n--;
            dir = (dir + 1) % 4;
        }
        return res;
    }
};