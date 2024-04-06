class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (string token : tokens) {
            if (token.size() == 1 && token[0] < '0') {
                int right = s.top(); s.pop();
                int left = s.top(); s.pop();
                if (token == "+") s.push(left + right);
                else if (token == "-") s.push(left - right);
                else if (token == "*") s.push(left * right);
                else s.push(left / right);
            }
            else s.push(stoi(token));
        }
        return s.top();
    }
};