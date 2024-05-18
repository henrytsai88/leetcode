class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') stk.push(i);
            else {
                stk.pop();
                if (stk.empty()) stk.push(i);
                else res = max(res, i - stk.top());
            }
        }
        return res;
    }
};