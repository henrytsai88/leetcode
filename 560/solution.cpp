class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefixSum(nums.size());
        prefixSum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        int res = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (prefixSum[i] == k) res++;
            int target = prefixSum[i] - k;
            if (m.count(target)) res += m[target];
            m[prefixSum[i]]++;
        }
        return res;
    }
};