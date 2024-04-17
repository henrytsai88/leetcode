class Solution {
public:
    void expand(int left, int right, string& s, int& start, int& length) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        if (--right - ++left + 1 > length) {
            start = left;
            length = right - left + 1;
        }
    }
    string longestPalindrome(string s) {
        int start, length = 0;
        for (int i = 0; i < s.size(); i++) {
            expand(i, i, s, start, length);
            expand(i, i + 1, s, start, length);
        }
        return s.substr(start, length);
    }
};