class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (vector<int>& p : prerequisites) {
            int from = p[1], to = p[0];
            adj[from].push_back(to);
            inDegree[to]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) if (inDegree[i] == 0) q.push(i);
        while (!q.empty()) {
            int cur = q.front(); q.pop(); numCourses--;
            for (int next : adj[cur]) {
                if (--inDegree[next] == 0) q.push(next);
            }
        }
        return numCourses == 0;
    }
};