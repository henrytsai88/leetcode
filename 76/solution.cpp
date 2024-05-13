class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);
        for (char c : t) freq[c]++;
        int start = 0, end = 0, count = t.size(), minStart, minLen = INT_MAX;
        while (end < s.size()) {
            if (freq[s[end]] > 0) count--;
            freq[s[end]]--;
            end++;
            while (count == 0) {
                if (end - start < minLen) {
                    minStart = start;
                    minLen = end - start;
                }
                freq[s[start]]++;
                if (freq[s[start]] > 0) count++;
                start++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};