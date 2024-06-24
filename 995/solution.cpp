class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flipsInWindow = 0, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k){
                if (nums[i - k] == 2) flipsInWindow--;
            }
            if (flipsInWindow % 2 == nums[i]) {
                if (i + k > nums.size()) return -1;
                nums[i] = 2;
                flipsInWindow++;
                res++;
            }
        }
        return res;
    }
};