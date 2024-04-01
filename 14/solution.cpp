class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        size_t n = INT_MAX;
        for (string str : strs) n = min(n, str.size());
        string prefix;
        for (int i = 0; i < n; i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != c) return prefix;
            }
            prefix += c;
        }
        return prefix;
    }
};