class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(52, 0);
        for (char c : s) {
            if (isupper(c)) freq[c - 'A']++;
            else freq[c - 'a' + 26]++;
        }
        int count = 0;
        for (int i = 0; i < 52; i++) count += (freq[i] / 2) * 2;
        for (int i = 0; i < 52; i++) if (freq[i] % 2 == 1) return count + 1;
        return count;
    }
};