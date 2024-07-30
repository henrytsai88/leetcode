class Solution {
public:
    int minimumDeletions(string s) {
        int res = 0, bCount = 0;
        for (char c : s) {
            if (c == 'a') res = min(res + 1, bCount);
            else bCount++;
        }
        return res;
    }
};