class Solution {
public:
    int reverse(int x) {
        int sign = x < 0 ? -1 : 1;
        x = abs(x);
        int res = 0;
        while (x) {
            if (res > INT_MAX / 10 || res == INT_MAX / 10 && x % 10 > INT_MAX % 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return sign * res;
    }
};