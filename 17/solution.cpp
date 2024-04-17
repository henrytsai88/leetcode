class Solution {
public:
    void helper(string& digits, int i, string s, vector<string>& res, vector<string>& v) {
        if (i == digits.size()) {
            res.push_back(s);
            return;
        }
        for (char c : v[digits[i] - '0']) {
            helper(digits, i + 1, s + c, res, v);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if (digits.size() > 0) helper(digits, 0, "", res, v);
        return res;
    }
};