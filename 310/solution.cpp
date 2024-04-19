class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for (vector<int>& edge : edges) {
            int from = edge[0], to = edge[1];
            adj[from].push_back(to);
            adj[to].push_back(from);
            degree[from]++;
            degree[to]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) if (degree[i] == 1) q.push(i);
        while (!q.empty()) {
            int size = q.size();
            if (size == n) break;
            for (int i = 0; i < size; i++) {
                int cur = q.front(); q.pop(); n--;
                for (int next : adj[cur]) {
                    if (--degree[next] == 1) q.push(next);
                }
            }
        }
        vector<int> res;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            res.push_back(cur);
        }
        return res;
    }
};