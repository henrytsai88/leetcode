class Solution {
public:
    void backtrack(int start, int n, int k, vector<int>& v, vector<vector<int>>& res) {
        if (k == 0) {
            res.push_back(v);
            return;
        }
        for (int i = start; i < n; i++) {
            v.push_back(i + 1);
            backtrack(i + 1, n, k - 1, v, res);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> v;
        backtrack(0, n, k, v, res);
        return res;
    }
};