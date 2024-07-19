class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> m1;
        unordered_map<string, int> m2;
        istringstream in(s);
        int i = 0, n = pattern.size();
        for (string str; in >> str; i++) {
            if (i == n || m1[pattern[i]] != m2[str]) return false;
            m1[pattern[i]] = m2[str] = i + 1;
        }
        return i == n;
    }
};