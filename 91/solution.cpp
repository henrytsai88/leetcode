class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 1) return s[0] != '0';
        int n = s.size();
        int pre2 = 1, pre = s[0] != '0', cur;
        for (int i = 1; i < n; i++) {
            cur = (s[i] != '0') * pre + ((s[i - 1] == '1') || (s[i - 1] == '2' && s[i] < '7')) * pre2;
            pre2 = pre;
            pre = cur;
        }
        return cur;
    }
};