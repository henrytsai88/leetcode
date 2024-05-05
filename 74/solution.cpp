class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int i = mid / n, j = mid % n;
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};