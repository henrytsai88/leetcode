class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        map<int, int> m;
        for (int i = 0; i < difficulty.size(); i++) {
            m[difficulty[i]] = max(m[difficulty[i]], profit[i]);
        }
        int maxProfit = 0;
        for (auto& p : m) {
            maxProfit = max(maxProfit, p.second);
            p.second = maxProfit;
        }
        int res = 0;
        for (int w : worker) {
            auto it = prev(m.upper_bound(w));
            res += it->second;
        }
        return res;
    }
};