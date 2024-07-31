class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int width = books[i - 1][0], height = books[i - 1][1];
            dp[i] = dp[i - 1] + height;
            for (int j = i - 1; j > 0; j--) {
                if (width + books[j - 1][0] > shelfWidth) break;
                width += books[j - 1][0];
                height = max(height, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + height);
            }
        }
        return dp[n];
    }
};