class Solution {
public:
    void buildGraph(vector<vector<int>>& conditions, vector<vector<int>>& adj, vector<int>& inDegree) {
        for (vector<int>& c : conditions) {
            int from = c[0] - 1, to = c[1] - 1;
            adj[from].push_back(to);
            inDegree[to]++;
        }
    }
    void topologicalSort(int n, vector<vector<int>>& adj, vector<int>& inDegree, vector<int>& order) {
        queue<int> q;
        for (int i = 0; i < n; i++) if (inDegree[i] == 0) q.push(i);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            order.push_back(cur);
            for (int next : adj[cur]) {
                if (--inDegree[next] == 0) q.push(next);
            }
        }
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> adj1(k), adj2(k);
        vector<int> inDegree1(k), inDegree2(k);
        buildGraph(rowConditions, adj1, inDegree1);
        buildGraph(colConditions, adj2, inDegree2);
        vector<int> order1, order2;
        topologicalSort(k, adj1, inDegree1, order1);
        topologicalSort(k, adj2, inDegree2, order2);
        if (order1.size() != k || order2.size() != k) return {};
        vector<vector<int>> res(k, vector<int>(k));
        unordered_map<int, int> m;
        for (int i = 0; i < k; i++) {
            m[order2[i]] = i;
        }
        for (int i = 0; i < k; i++) {
            res[i][m[order1[i]]] = order1[i] + 1;
        }
        return res;
    }
};