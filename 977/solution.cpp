class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, i = nums.size();
        vector<int> res(nums.size(), 0);
        while (i) {
            if (abs(nums[left]) < abs(nums[right])) res[--i] = pow(nums[right--], 2);
            else res[--i] = pow(nums[left++], 2);
        }
        return res;
    }
};