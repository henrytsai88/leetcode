class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m = {{0, -1}};
        int sum = 0, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] ? 1 : -1;
            if (m.count(sum)) res = max(res, i - m[sum]);
            else m[sum] = i;
        }
        return res;
    }
};