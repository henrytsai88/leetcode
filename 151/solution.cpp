class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        istringstream in(s);
        string str, res;
        while (in >> str) {
            reverse(str.begin(), str.end());
            res += str + ' ';
        }
        res.pop_back();
        return res;
    }
};