class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> stk;
        for (int i = 0; i < n; ) {
            if (path[i] == '/') i++;
            else {
                string str;
                while (i < n && path[i] != '/') str += path[i++];
                if (str == ".");
                else if (str == "..") {
                    if (!stk.empty()) stk.pop();
                }
                else stk.push(str);
            }
        }
        string res;
        while (!stk.empty()) {
            res = '/' + stk.top() + res;
            stk.pop();
        }
        return res.empty() ? "/" : res;
    }
};