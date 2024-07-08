class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            v.push_back(i);
        }
        int i = 0, iter = n - 1;
        while (iter--) {
            i = (i + k - 1) % v.size();
            v.erase(v.begin() + i);
        }
        return v[0];
    }
};