class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), res = 0;
        priority_queue<pair<int, int>> pq;
        pq.push({0, 0});
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            while (visited[pq.top().second]) pq.pop();
            auto cur = pq.top(); pq.pop();
            int next = cur.second;
            visited[next] = true;
            res -= cur.first;
            for (int j = 0; j < n; j++) {
                if (visited[j]) continue;
                int dist = abs(points[next][0] - points[j][0]) + abs(points[next][1] - points[j][1]);
                pq.push({-dist, j});
            }
        }
        return res;
    }
};