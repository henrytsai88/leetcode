class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int s0 = 0, s1 = -prices[0], s2 = INT_MIN;
        for (int i = 1; i < n; i++) {
            int prev_s0 = s0;
            s0 = max(s0, s2);
            s2 = s1 + prices[i];
            s1 = max(s1, prev_s0 - prices[i]);
        }
        return max(s0, s2);
    }
};