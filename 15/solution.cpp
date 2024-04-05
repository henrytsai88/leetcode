class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum < target) left++;
                else if (sum > target) right--;
                else {
                    vector<int> v = {nums[i], nums[left], nums[right]};
                    res.push_back(v);
                    while (left < right && nums[left] == v[1]) left++;
                    while (left < right && nums[right] == v[2]) right--;
                }
            }
        }
        return res;
    }
};