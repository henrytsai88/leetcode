class Solution {
public:
    int numSteps(string s) {
        int step = 0, carry = 0;
        for (int i = s.size() - 1; i > 0; i--) {
            if (s[i] - '0' + carry == 1) {
                carry = 1;
                step += 2;
            }
            else step++;
        }
        return step + carry;
    }
};