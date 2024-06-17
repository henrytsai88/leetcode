class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0, right = sqrt(c);
        while (left <= right) {
            int target = c - left * left;
            if (right * right == target) return true;
            else if (right * right > target) right--;
            else left++;
        }
        return false;
    }
};