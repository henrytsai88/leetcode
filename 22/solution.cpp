class Solution {
public:
    void helper(int left, int right, string& s, vector<string>& res) {
        if (left == 0 && right == 0) {
            res.push_back(s);
            return;
        }
        s += '(';
        if (left > 0) helper(left - 1, right, s, res);
        s.pop_back();
        s += ')';
        if (right > 0 && left < right) helper(left, right - 1, s, res);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        helper(n, n, s, res);
        return res;
    }
};