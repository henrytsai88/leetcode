class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), res = nums[0];
        for (int i = 1, imax = res, imin = res; i < n; i++) {
            if (nums[i] < 0) swap(imax, imin);
            imax = max(nums[i], nums[i] * imax);
            imin = min(nums[i], nums[i] * imin);
            res = max(res, imax);
        }
        return res;
    }
};