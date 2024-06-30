class UnionFind {
public:
    vector<int> parent;
    int distinctComponents;
    UnionFind(int n) {
        for (int i = 0; i <= n; i++) parent.push_back(i);
        distinctComponents = n;
    }
    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
    bool unite(int a, int b) {
        if (find(a) == find(b)) return false;
        parent[find(a)] = b;
        distinctComponents--;
        return true;
    }
    bool united() {
        return distinctComponents == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind alice(n), bob(n);
        int edgesAdded = 0;
        for (vector<int>& edge : edges) {
            int type = edge[0], from = edge[1], to = edge[2];
            if (type == 3) {
                edgesAdded += alice.unite(from, to) | bob.unite(from, to);
            }
        }
        for (vector<int>& edge : edges) {
            int type = edge[0], from = edge[1], to = edge[2];
            if (type == 1) {
                edgesAdded += alice.unite(from, to);
            }
            else if (type == 2) {
                edgesAdded += bob.unite(from, to);
            }
        }
        return alice.united() && bob.united() ? edges.size() - edgesAdded : -1;
    }
};