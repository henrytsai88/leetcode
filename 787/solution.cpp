class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for (int i = 0; i <= k; i++) {
            vector<int> newDist(dist);
            for (vector<int>& flight : flights) {
                int from = flight[0], to = flight[1], price = flight[2];
                if (dist[from] != INT_MAX) {
                    newDist[to] = min(newDist[to], dist[from] + price);
                }
            }
            dist = newDist;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};