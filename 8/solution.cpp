class Solution {
public:
    int myAtoi(string s) {
        int base = 0, sign = 1, i = 0;
        while (s[i] == ' ') i++;
        if (s[i] == '+' || s[i] == '-') {
            sign = 1 - 2 * (s[i++] == '-');
        }
        while (i < s.size() && isdigit(s[i])) {
            if (base > INT_MAX / 10 || base == INT_MAX / 10 && s[i] > '7') {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            base = base * 10 + (s[i++] - '0');
        }
        return sign * base;
    }
};