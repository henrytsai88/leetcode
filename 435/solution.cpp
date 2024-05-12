class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [] (const auto& p, const auto& q) {
            return p[1] < q[1];
        });
        int res = 0, right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < right) res++;
            else right = intervals[i][1];
        }
        return res;
    }
};