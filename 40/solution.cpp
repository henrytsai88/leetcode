class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& v, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(v);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) continue;
            if (i == start || candidates[i] != candidates[i - 1]) {
                v.push_back(candidates[i]);
                backtrack(candidates, target - candidates[i], i + 1, v, res);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> v;
        backtrack(candidates, target, 0, v, res);
        return res;
    }
};