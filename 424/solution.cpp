class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int res = 0;
        for (int left = 0, right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            int maxFreq = *max_element(freq.begin(), freq.end());
            if (right - left + 1 - maxFreq > k) freq[s[left++] - 'A']--;
            else res = max(res, right - left + 1);
        }
        return res;
    }
};