class Solution {
public:
    int minimumChairs(string s) {
        int res = 0, count = 0;
        for (char c : s) {
            if (c == 'E') res = max(res, ++count);
            else count--;
        }
        return res;
    }
};