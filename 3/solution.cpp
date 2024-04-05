class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int length = 0, start = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            if (m.count(s[i])) {
                length = max(length, i - start);
                start = max(start, m[s[i]] + 1);
            }
            m[s[i]] = i;
        }
        return max(length, n - start);
    }
};