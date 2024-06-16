class Solution {
public:
    map<pair<int, int>, int> dp;
    int dfs(vector<int>& nums, int target, int i) {
        if (i == nums.size()) {
            return target == 0;
        }
        if (dp.count({i, target})) return dp[{i, target}];
        int total = 0;
        total += dfs(nums, target + nums[i], i + 1);
        total += dfs(nums, target - nums[i], i + 1);
        dp[{i, target}] = total;
        return total;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, -target, 0);
    }
};