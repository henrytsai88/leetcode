class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0, count = 0;
        for (int num : nums) {
            if (!count) majority = num;
            count += (num == majority) ? 1 : -1;
        }
        return majority;
    }
};