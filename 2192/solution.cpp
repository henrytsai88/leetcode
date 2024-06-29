class Solution {
public:
    void dfs(int parent, int cur, vector<vector<int>>& res, vector<vector<int>>& adj) {
        for (int next : adj[cur]) {
            if (!res[next].empty() && res[next].back() == parent) continue;
            res[next].push_back(parent);
            dfs(parent, next, res, adj);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n), adj(n);
        for (vector<int>& edge : edges) {
            int from = edge[0], to = edge[1];
            adj[from].push_back(to);
        }
        for (int i = 0; i < n; i++) {
            dfs(i, i, res, adj);
        }
        return res;
    }
};