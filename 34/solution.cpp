class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start = -1, end = -1, left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                start = mid;
                right = mid - 1;
            }
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                end = mid;
                left = mid + 1;
            }
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return {start, end};
    }
};