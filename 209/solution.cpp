class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, sum = 0, res = INT_MAX;
        while (right < nums.size()) {
            sum += nums[right++];
            while (sum >= target) {
                res = min(res, right - left);
                sum -= nums[left++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};