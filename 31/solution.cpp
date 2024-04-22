class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), pivot;
        for (pivot = n - 2; pivot >= 0; pivot--) {
            if (nums[pivot] < nums[pivot + 1]) {
                break;
            }
        }
        if (pivot >= 0) {
            for (int i = n - 1; i > pivot; i--) {
                if (nums[i] > nums[pivot]) {
                    swap(nums[i], nums[pivot]);
                    break;
                }
            }
        }
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};