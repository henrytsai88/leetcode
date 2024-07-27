class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); i++) {
            int samePoint = 1;
            unordered_map<double, int> m;
            for (int j = i + 1; j < points.size(); j++) {
                int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0], y2 = points[j][1];
                if (x1 == x2 && y1 == y2) {
                    samePoint++;
                }
                else if (x1 == x2) {
                    m[INT_MAX]++;
                }
                else {
                    double slope = (double) (y2 - y1) / (x2 - x1);
                    m[slope]++;
                }
            }
            int localMax = 0;
            for (auto& p : m) {
                localMax = max(localMax, p.second);
            }
            localMax += samePoint;
            res = max(res, localMax);
        }
        return res;
    }
};