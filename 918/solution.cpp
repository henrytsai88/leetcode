class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0, maxSum = nums[0], curMax = 0, minSum = nums[0], curMin = 0;
        for (int num : nums) {
            curMax = max(curMax + num, num);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + num, num);
            minSum = min(minSum, curMin);
            sum += num;
        }
        return maxSum > 0 ? max(maxSum, sum - minSum) : maxSum;
    }
};