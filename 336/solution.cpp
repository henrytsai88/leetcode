class Solution {
public:
    bool isPalindrome(string& word) {
        int left = 0, right = word.size() - 1;
        while (left < right) {
            if (word[left++] != word[right--]) return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> m;
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            string reversed = words[i];
            reverse(reversed.begin(), reversed.end());
            m[reversed] = i;
        }
        for (int i = 0; i < n; i++) {
            string left = "", right = words[i];
            for (int j = 0; j < words[i].size(); j++) {
                if (m.count(left) && isPalindrome(right) && m[left] != i) {
                    res.push_back({i, m[left]});
                    if (left == "") res.push_back({m[left], i});
                }
                if (m.count(right) && isPalindrome(left) && m[right] != i) {
                    res.push_back({m[right], i});
                }
                left += right[0];
                right.erase(0, 1);
            }
        }
        return res;
    }
};