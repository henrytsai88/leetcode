class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(), res = 0;
        for (int i = 1; i < n - 1; i++) {
            vector<int> less(2, 0), greater(2, 0);
            for (int j = 0; j < n; j++) {
                if (rating[i] < rating[j]) {
                    less[j > i]++;
                }
                if (rating[i] > rating[j]) {
                    greater[j > i]++;
                }
            }
            res += less[0] * greater[1] + greater[0] * less[1];
        }
        return res;
    }
};