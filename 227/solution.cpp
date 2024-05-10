class Solution {
public:
    int calculate(string s) {
        stringstream ss('+' + s);
        int res = 0, last = 0, num;
        char op;
        while (ss >> op >> num) {
            if (op == '+' || op == '-') {
                res += last;
                last = op == '+' ? num : -num;
            }
            else {
                last = op == '*' ? last * num : last / num;
            }
        }
        return res + last;
    }
};