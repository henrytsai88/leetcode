class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n);
        for (vector<int>& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        sort(degree.begin(), degree.end());
        long long res = 0;
        for (long long i = 0; i < n; i++) {
            res += (i + 1) * degree[i];
        }
        return res;
    }
};