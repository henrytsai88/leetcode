class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                m[stop].push_back(i);
            }
        }
        if (!m.count(source) || !m.count(target)) return -1;
        queue<pair<int, int>> q;
        q.push({source, 0});
        vector<bool> busVisited(routes.size(), false);
        unordered_set<int> stopVisited;
        while (!q.empty()) {
            auto[cur, step] = q.front(); q.pop();
            if (cur == target) return step;
            if (stopVisited.count(cur)) continue;
            stopVisited.insert(cur);
            for (int i : m[cur]) {
                if (busVisited[i]) continue;
                busVisited[i] = true;
                for (int stop : routes[i]) {
                    q.push({stop, step + 1});
                }
            }
        }
        return -1;
    }
};