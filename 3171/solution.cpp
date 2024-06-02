class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        vector<int> count(30, 0);
        int res = INT_MAX, sum = (1 << 30) - 1;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            sum &= nums[i];
            res = min(res, abs(k - sum));
            for (int c = 0; c < 30; c++) {
                if (((1 << c) & nums[i]) == 0) count[c]++;
            }
            while (sum < k) {
                for (int c = 0; c < 30; c++) {
                    if (((1 << c) & nums[j]) == 0) if (--count[c] == 0) sum |= (1 << c);
                }
                res = min(res, abs(k - sum));
                j++;
            }
        }
        return res;
    }
};