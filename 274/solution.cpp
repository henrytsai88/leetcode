class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> buckets(n + 1, 0);
        for (int citation : citations) {
            int i = min(citation, n);
            buckets[i]++;
        }
        int count = 0;
        for (int i = n; i > 0; i--) {
            count += buckets[i];
            if (count >= i) return i;
        }
        return 0;
    }
};