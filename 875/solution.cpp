class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 0;
        for (int pile : piles) right = max(right, pile);
        while (left < right) {
            int mid = (left + right) / 2, time = 0;
            for (int pile : piles) time += ceil((double) pile / mid);
            if (time > h) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};