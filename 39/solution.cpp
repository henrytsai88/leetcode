class Solution {
public:
    void helper(vector<int>& candidates, int target, int i, vector<int>& v, vector<vector<int>>& res) {
        if (i == candidates.size() || target < 0) return;
        if (target == 0) {
            res.push_back(v);
            return;
        }
        v.push_back(candidates[i]);
        helper(candidates, target - candidates[i], i, v, res);
        v.pop_back();
        helper(candidates, target, i + 1, v, res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> v;
        helper(candidates, target, 0, v, res);
        return res;
    }
};