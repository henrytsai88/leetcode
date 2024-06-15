class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> m;
        for (vector<int>& time : times) {
            m[time[0]].push_back({time[1], time[2]});
        }
        priority_queue<pair<int, int>> pq;
        pq.push({0, k});
        vector<bool> visited(n + 1, false);
        int res = 0;
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            if (visited[cur.second]) continue;
            visited[cur.second] = true;
            res = -cur.first;
            for (pair<int, int>& p : m[cur.second]) {
                int next = p.first, weight = p.second;
                pq.push({cur.first - weight, next});
            }
            if (--n == 0) return res;
        }
        return -1;
    }
};