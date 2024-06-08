class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> s;
        nums[0] = nums[0] % k;
        for (int i = 1; i < n; i++) {
            nums[i] = (nums[i] + nums[i - 1]) % k;
            if (s.count(nums[i]) || nums[i] == 0) return true;
            s.insert(nums[i - 1]);
        }
        return false;
    }
};