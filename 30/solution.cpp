class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> m;
        for (string& word : words) m[word]++;
        vector<int> res;
        int n = s.size(), num = words.size(), len = words[0].size();
        for (int i = 0; i < len; i++) {
            unordered_map<string, int> m2 = m;
            for (int left = 0, right = 0; i + (right + 1) * len - 1 < n; right++) {
                if (right - left == num) {
                    int start = i + left * len;
                    string substr = s.substr(start, len);
                    if (++m2[substr] == 0) m2.erase(substr);
                    left++;
                }
                int start = i + right * len;
                string substr = s.substr(start, len);
                if (--m2[substr] == 0) m2.erase(substr);
                if (m2.empty()) res.push_back(i + left * len);
            }
        }
        return res;
    }
};