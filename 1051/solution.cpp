class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> buckets(101, 0);
        for (int height : heights) buckets[height]++;
        int res = 0, index = 0;
        for (int i = 1; i <= 100; i++) {
            while (buckets[i] > 0) {
                if (i != heights[index++]) res++;
                buckets[i]--;
            }
        }
        return res;
    }
};