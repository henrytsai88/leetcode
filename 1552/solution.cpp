class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left = 1, right = position.back() - position[0];
        while (left < right) {
            int mid = right - (right - left) / 2;
            int placed = 1, prev = position[0];
            for (int i = 1; i < position.size() && placed < m; i++) {
                if (position[i] - prev >= mid) {
                    placed++;
                    prev = position[i];
                }
            }
            if (placed == m) left = mid;
            else right = mid - 1;
        }
        return left;
    }
};