class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int> stk;
        vector<int> pair(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') stk.push(i);
            else if (s[i] == ')') {
                int j = stk.top(); stk.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }
        string res;
        for (int i = 0, dir = 1; i < n; i += dir) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];
                dir *= -1;
            }
            else {
                res += s[i];
            }
        }
        return res;
    }
};