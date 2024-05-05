class Solution {
public:
    double myPow(double x, int n) {
        if (n > 0) {
            x = 1 / x;
            n *= -1;
        }
        double res = 1;
        while (n < 0) {
            if (n % 2) res /= x;
            x *= x;
            n /= 2;
        }
        return res;
    }
};