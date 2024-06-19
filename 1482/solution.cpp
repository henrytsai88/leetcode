class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(), left = 0, right = 0;
        if (n < (long) m * k) return -1;
        for (int day : bloomDay) right = max(right, day);
        while (left < right) {
            int mid = (left + right) / 2;
            int bouquets = 0, count = 0;
            for (int i = 0; i < n; i++) {
                if (mid >= bloomDay[i]) {
                    if (++count == k) {
                        bouquets++;
                        count = 0;
                    }
                }
                else count = 0;
            }
            if (bouquets < m) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};