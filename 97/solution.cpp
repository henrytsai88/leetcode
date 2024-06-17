class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size()) return false;
        vector<bool> pre(n + 1, false), cur(n + 1, false);
        pre[0] = true;
        for (int j = 1; j <= n; j++) {
            pre[j] = pre[j - 1] && (s3[j - 1] == s2[j - 1]);
        }
        for (int i = 1; i <= m; i++) {
            cur[0] = pre[0] && (s3[i - 1] == s1[i - 1]);
            for (int j = 1; j <= n; j++) {
                cur[j] = pre[j] && (s3[i + j - 1] == s1[i - 1]) || cur[j - 1] && (s3[i + j - 1] == s2[j - 1]);
            }
            swap(pre, cur);
        }
        return pre[n];
    }
};