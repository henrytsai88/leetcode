class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), res = 0;
        vector<int> leftIdx(n), rightIdx(n);
        leftIdx[0] = -1, rightIdx[n - 1] = n;
        for (int i = 1; i < n; i++) {
            int j = i - 1;
            while (j >= 0 && heights[j] >= heights[i]) j = leftIdx[j];
            leftIdx[i] = j;
        }
        for (int i = n - 2; i >= 0; i--) {
            int j = i + 1;
            while (j < n && heights[j] >= heights[i]) j = rightIdx[j];
            rightIdx[i] = j;
        }
        for (int i = 0; i < n; i++) {
            res = max(res, heights[i] * (rightIdx[i] - leftIdx[i] - 1));
        }
        return res;
    }
};