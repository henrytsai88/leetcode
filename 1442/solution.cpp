class Solution {
public:
    int countTriplets(vector<int>& arr) {
        arr.insert(arr.begin(), 0);
        int n = arr.size(), res = 0, prefix = 0;
        unordered_map<int, int> count, total;
        for (int i = 0; i < n; i++) {
            prefix ^= arr[i];
            res += count[prefix]++ * (i - 1) - total[prefix];
            total[prefix] += i;
        }
        return res;
    }
};