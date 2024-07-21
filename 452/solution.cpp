class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int res = 1, right = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            right = min(right, points[i][1]);
            if (points[i][0] > right) {
                right = points[i][1];
                res++;
            }
        }
        return res;
    }
};