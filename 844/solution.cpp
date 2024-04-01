class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1, back;
        while (true) {
            back = 0;
            while (i >= 0 && (s[i] == '#' || back)) {
                back += (s[i--] == '#') ? 1 : -1;
            }
            back = 0;
            while (j >= 0 && (t[j] == '#' || back)) {
                back += (t[j--] == '#') ? 1 : -1;
            }
            if (i >= 0 && j >= 0 && s[i] == t[j]) {i--; j--;}
            else break;
        }
        return i == -1 && j == -1;
    }
};