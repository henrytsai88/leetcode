class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.size(), n = s.size();
        vector<unsigned long long> pre(n + 1), cur(n + 1);
        for (int j = 0; j <= n; j++) pre[j] = 1;
        for (int i = 1; i <= m; i++) {
            cur[0] = 0;
            for (int j = 1; j <= n; j++) {
                if (t[i - 1] == s[j - 1]) cur[j] = pre[j - 1] + cur[j - 1];
                else cur[j] = cur[j - 1];
            }
            swap(pre, cur);
        }
        return pre[n];
    }
};