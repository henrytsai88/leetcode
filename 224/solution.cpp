class Solution {
public:
    int calculate(string s) {
        s += '+';
        stack<int> stk;
        int num = 0, res = 0;
        int sign = 1;
        for (char c : s) {
            if (c == ' ') continue;
            else if (isdigit(c)) num = num * 10 + (c - '0');
            else if (c == '+' || c == '-') {
                res += sign * num;
                num = 0;
                sign = c == '+' ? 1 : -1;
            }
            else if (c == '(') {
                stk.push(res);
                stk.push(sign);
                res = 0;
                sign = 1;
            }
            else {
                res += sign * num;
                res *= stk.top(); stk.pop();
                res += stk.top(); stk.pop();
                num = 0;
            }
        }
        return res;
    }
};