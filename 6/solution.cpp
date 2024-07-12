class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> words(numRows);
        int i = 0, dir = -1;
        for (char c : s) {
            words[i] += c;
            if (i == 0 || i == numRows - 1) dir *= -1;
            i += dir;
        }
        string res;
        for (string word : words) res += word;
        return res;
    }
};