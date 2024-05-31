class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2, 0);
        int mask = 0;
        for (int num : nums) mask ^= num;
        if (mask != INT_MIN) mask &= -mask;
        for (int num : nums) {
            if (num & mask) res[1] ^= num;
            else res[0] ^= num;
        }
        return res;
    }
};