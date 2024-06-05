class Solution {
public:
    int helper(vector<int>& nums, int left, int right) {
        int pre2 = nums[left], pre = max(nums[left], nums[left + 1]);
        for (int i = left + 2; i <= right; i++) {
            int cur = max(pre, nums[i] + pre2);
            pre2 = pre;
            pre = cur;
        }
        return pre;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        return max(helper(nums, 0, n - 2), helper(nums, 1, n - 1));
    }
};