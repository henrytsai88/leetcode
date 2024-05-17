class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (n < m) return findMedianSortedArrays(nums2, nums1);
        int left = 0, right = m, leftPartitionSize = (m + n + 1) / 2;
        while (left <= right) {
            int partitionX = (left + right) / 2;
            int partitionY = leftPartitionSize - partitionX;
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];
            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((m + n) % 2) return max(maxLeftX, maxLeftY);
                return (double) (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
            }
            else if (maxLeftX > minRightY) right = partitionX - 1;
            else left = partitionX + 1;
        }
        return -1;
    }
};