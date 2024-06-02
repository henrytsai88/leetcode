class Solution {
public:
    string clearStars(string s) {
        unordered_map<char, vector<int>> m;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (!m[c].empty()) {
                        s[m[c].back()] = '*';
                        m[c].pop_back();
                        break;
                    }
                }
            }
            else m[s[i]].push_back(i);
        }
        string res;
        for (char c : s) {
            if (c != '*') res += c;
        }
        return res;
    }
};