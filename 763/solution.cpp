class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> v(26, 0);
        for (int i = 0; i < s.size(); i++) v[s[i] - 'a'] = i;
        vector<int> res;
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); i++) {
            right = max(right, v[s[i] - 'a']);
            if (i == right) {
                res.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return res;
    }
};