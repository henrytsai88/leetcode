class Solution {
public:
    void backtrack(vector<int>& nums, int start, vector<int>& v, vector<vector<int>>& res) {
        res.push_back(v);
        for (int i = start; i < nums.size(); i++) {
            if (i == start || nums[i] != nums[i - 1]) {
                v.push_back(nums[i]);
                backtrack(nums, i + 1, v, res);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> v;
        backtrack(nums, 0, v, res);
        return res;
    }
};