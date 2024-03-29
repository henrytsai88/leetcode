class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.size(), j = b.size(), carry = 0;
        while (i || j || carry) {
            if (i) carry += a[--i] - '0';
            if (j) carry += b[--j] - '0';
            res += '0' + (carry % 2);
            carry /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};