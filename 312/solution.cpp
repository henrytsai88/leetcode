class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> v;
        v.push_back(1);
        for (int num : nums) if (num != 0) v.push_back(num);
        v.push_back(1);
        int n = v.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int k = 2; k < n; k++) {
            for (int left = 0; left + k < n; left++) {
                int right = left + k;
                int maxCoins = 0;
                for (int i = left + 1; i < right; i++) {
                    int coins = v[left] * v[i] * v[right];
                    coins += dp[left][i];
                    coins += dp[i][right];
                    maxCoins = max(maxCoins, coins);
                }
                dp[left][right] = maxCoins;
            }
        }
        return dp[0][n - 1];
    }
};