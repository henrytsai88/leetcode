class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0, prev = 0, cur = 0;
        for (int num : nums) {
            cur = max(prev, prev2 + num);
            prev2 = prev;
            prev = cur;
        }
        return cur;
    }
};