class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<int> pre(n + 1, 0), cur(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) cur[j] = 1 + pre[j - 1];
                else cur[j] = max(cur[j - 1], pre[j]);
            }
            swap(pre, cur);
        }
        return pre[n];
    }
};