class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k >= prices.size() / 2) {
            int profit = 0;
            for (int i = 1; i < prices.size(); i++) {
                profit += max(prices[i] - prices[i - 1], 0);
            }
            return profit;
        }
        vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
        for (int price : prices) {
            for (int i = 1; i <= k; i++) {
                buy[i] = max(buy[i], sell[i - 1] - price);
                sell[i] = max(sell[i], buy[i] + price);
            }
        }
        return sell[k];
    }
};