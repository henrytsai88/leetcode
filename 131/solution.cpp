class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
    void backtrack(string& s, int start, vector<string>& v, vector<vector<string>>& res) {
        if (start == s.size()) {
            res.push_back(v);
            return;
        }
        string substr;
        for (int i = start; i < s.size(); i++) {
            substr += s[i];
            if (isPalindrome(substr)) {
                v.push_back(substr);
                backtrack(s, i + 1, v, res);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> v;
        backtrack(s, 0, v, res);
        return res;
    }
};