class Solution {
public:
    int romanToInt(string s) {
        map<char, int> romanTable = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int res = 0, n = s.size();
        for (int i = 0; i < n - 1; i++) {
            if (romanTable[s[i]] < romanTable[s[i + 1]]) res -= romanTable[s[i]];
            else res += romanTable[s[i]];
        }
        res += romanTable[s[n - 1]];
        return res;
    }
};