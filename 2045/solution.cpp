class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (vector<int>& edge : edges) {
            int from = edge[0], to = edge[1];
            adj[from].push_back(to);
            adj[to].push_back(from);
        }
        vector<vector<int>> minTime(n + 1, vector<int>(2, INT_MAX));
        queue<pair<int, int>> q;
        q.push({1, 0});
        while (!q.empty()) {
            auto [cur, prevTime] = q.front(); q.pop();
            bool isRedSignal = (prevTime / change) % 2;
            int waitTime = isRedSignal ? change - (prevTime % change) : 0;
            int newTime = prevTime + waitTime + time;
            for (int next : adj[cur]) {
                if (newTime < minTime[next][0]) {
                    minTime[next][0] = newTime;
                    q.push({next, newTime});
                }
                else if (newTime > minTime[next][0] && newTime < minTime[next][1]) {
                    if (next == n) return newTime;
                    minTime[next][1] = newTime;
                    q.push({next, newTime});
                }
            }
        }
        return -1;
    }
};