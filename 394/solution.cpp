class Solution {
public:
    string helper(string& s, int& i) {
        string res;
        while (i < s.size() && s[i] != ']') {
            if (isalpha(s[i])) res += s[i++];
            else {
                int k = 0;
                while (i < s.size() && isdigit(s[i])) k = k * 10 + s[i++] - '0';
                i++;
                string substr = helper(s, i);
                while (k--) res += substr;
                i++;
            }
        }
        return res;
    }
    string decodeString(string s) {
        int i = 0;
        return helper(s, i);
    }
};