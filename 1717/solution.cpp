class Solution {
public:
    int remove(string& s, string r, int x) {
        int i = 0, res = 0;
        for (int j = 0; j < s.size(); j++) {
            s[i++] = s[j];
            if (i > 1 && s[i - 2] == r[0] && s[i - 1] == r[1]) {
                i -= 2;
                res += x;
            }
        }
        s.resize(i);
        return res;
    }
    int maximumGain(string s, int x, int y) {
        string a = "ab", b = "ba";
        if (x < y) {
            swap(x, y);
            swap(a, b);
        }
        return remove(s, a, x) + remove(s, b, y);
    }
};