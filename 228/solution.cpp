class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size(), start = 0;
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || nums[i + 1] != nums[i] + 1) {
                if (i == start) res.push_back(to_string(nums[start]));
                else res.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));
                start = i + 1;
            }
        }
        return res;
    }
};