class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 == 1) return false;
        sum /= 2;
        bitset<10001> dp(1);
        for (int num : nums) {
            dp |= dp << num;
        }
        return dp[sum];
    }
};