class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        if (m < n) return {};
        vector<int> res;
        vector<int> sFreq(26, 0), pFreq(26, 0);
        for (int i = 0; i < n; i++) sFreq[s[i] - 'a']++;
        for (int i = 0; i < n; i++) pFreq[p[i] - 'a']++;
        if (sFreq == pFreq) res.push_back(0);
        for (int i = n; i < m; i++) {
            sFreq[s[i] - 'a']++;
            sFreq[s[i - n] - 'a']--;
            if (sFreq == pFreq) res.push_back(i - n + 1);
        }
        return res;
    }
};