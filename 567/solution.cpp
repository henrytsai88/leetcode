class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26, 0);
        for (char c : s1) freq1[c - 'a']++;
        vector<int> freq2(26, 0);
        for (int i = 0, j = 0; j < s2.size(); j++) {
            freq2[s2[j] - 'a']++;
            if (j - i + 1 == s1.size()) {
                if (freq1 == freq2) return true;
                freq2[s2[i++] - 'a']--;
            }
        }
        return false;
    }
};