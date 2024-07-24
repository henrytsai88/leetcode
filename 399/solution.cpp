class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> adj;
    double dfs(string& src, string& dst, unordered_set<string>& visited) {
        if (src == dst) return 1;
        visited.insert(src);
        for (pair<string, double>& p : adj[src]) {
            string next = p.first;
            double weight = p.second;
            if (visited.count(next)) continue;
            double product = dfs(next, dst, visited);
            if (product != -1) return weight * product;
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            string from = equations[i][0], to = equations[i][1];
            double weight = values[i];
            adj[from].push_back({to, weight});
            adj[to].push_back({from, 1 / weight});
        }
        vector<double> res;
        unordered_set<string> visited;
        for (vector<string>& q : queries) {
            if (!adj.count(q[0]) || !adj.count(q[1])) res.push_back(-1);
            else res.push_back(dfs(q[0], q[1], visited));
            visited.clear();
        }
        return res;
    }
};