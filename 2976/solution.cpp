class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int inf = 25000001;
        vector<vector<int>> dist(26, vector<int>(26, inf));
        for (int i = 0; i < 26; i++) dist[i][i] = 0;
        for (int i = 0; i < original.size(); i++) {
            int from = original[i] - 'a', to = changed[i] - 'a', weight = cost[i];
            dist[from][to] = min(dist[from][to], weight);
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        long long res = 0;
        for (int i = 0; i < source.size(); i++) {
            int from = source[i] - 'a', to = target[i] - 'a';
            if (dist[from][to] == inf) return -1;
            res += dist[from][to];
        }
        return res;
    }
};