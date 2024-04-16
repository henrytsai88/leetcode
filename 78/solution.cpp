class Solution {
public:
    void helper(vector<int>& nums, int start, vector<int>& v, vector<vector<int>>& res) {
        res.push_back(v);
        for (int i = start; i < nums.size(); i++) {
            v.push_back(nums[i]);
            helper(nums, i + 1, v, res);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        helper(nums, 0, v, res);
        return res;
    }
};