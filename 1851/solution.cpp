class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        unordered_map<int, int> res;
        vector<int> Q = queries, res2;
        sort(intervals.begin(), intervals.end());
        sort(Q.begin(), Q.end());
        int i = 0, n = intervals.size();
        for (int q : Q) {
            while (i < n && intervals[i][0] <= q) {
                int l = intervals[i][0], r = intervals[i++][1];
                pq.push({r - l + 1, r});
            }
            while (!pq.empty() && q > pq.top()[1]) {
                pq.pop();
            }
            res[q] = pq.empty() ? -1 : pq.top()[0];
        }
        for (int q : queries) {
            res2.push_back(res[q]);
        }
        return res2;
    }
};