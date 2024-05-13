class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxLeft = height[left], maxRight = height[right], res = 0;
        while (left <= right) {
            if (maxLeft < maxRight) {
                if (height[left] < maxLeft) res += maxLeft - height[left];
                else maxLeft = height[left];
                left++;
            }
            else {
                if (height[right] < maxRight) res += maxRight - height[right];
                else maxRight = height[right];
                right--;
            }
        }
        return res;
    }
};