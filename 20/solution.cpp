class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                myStack.push(c);
            }
            else {
                if (myStack.empty() ||
                    c == ')' && myStack.top() != '(' ||
                    c == '}' && myStack.top() != '{' ||
                    c == ']' && myStack.top() != '[') {
                        return false;
                }
                myStack.pop();
            }
        }
        return myStack.empty();
    }
};