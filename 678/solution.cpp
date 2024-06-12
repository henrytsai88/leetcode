class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0, cmax = 0;
        for (char c : s) {
            if (c == '(') {
                cmax++;
                cmin++;
            }
            else if (c == ')') {
                cmax--;
                cmin--;
                if (cmax < 0) return false;
            }
            else {
                cmax++;
                cmin--;
            }
            cmin = max(cmin, 0);
        }
        return cmin == 0;
    }
};