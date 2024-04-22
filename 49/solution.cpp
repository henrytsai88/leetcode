class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for (string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            m[key].push_back(str);
        }
        vector<vector<string>> res;
        for (auto it = m.begin(); it != m.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};