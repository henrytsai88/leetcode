class Solution {
public:
    map<int, int> parent;
    int find(int node) {
        if (parent[node] == node) return node;
        return find(parent[node]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        for (int i = 1; i <= edges.size(); i++) {
            parent[i] = i;
        }
        for (vector<int> edge : edges) {
            if (find(edge[0]) == find(edge[1])) res = edge;
            else parent[find(edge[0])] = find(edge[1]);
        }
        return res;
    }
};