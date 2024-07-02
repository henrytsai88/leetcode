class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= n; j++) {
            int pIdx = j - 1;
            if (p[pIdx] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int sIdx = i - 1, pIdx = j - 1;
                if (s[sIdx] == p[pIdx] || p[pIdx] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[pIdx] == '*') {
                    dp[i][j] = dp[i][j - 2];
                    if (s[sIdx] == p[pIdx - 1] || p[pIdx - 1] == '.') {
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                    }
                }
            }
        }
        return dp[m][n];
    }
};