class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxMin = INT_MIN, minMax = INT_MAX;
        for (int i = 0; i < m; i++) {
            int val = matrix[i][0];
            for (int j = 1; j < n; j++) val = min(val, matrix[i][j]);
            maxMin = max(maxMin, val);
        }
        for (int j = 0; j < n; j++) {
            int val = matrix[0][j];
            for (int i = 1; i < m; i++) val = max(val, matrix[i][j]);
            minMax = min(minMax, val);
        }
        return maxMin == minMax ? vector<int>(1, maxMin) : vector<int>();
    }
};