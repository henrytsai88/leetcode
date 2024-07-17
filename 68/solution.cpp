class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        for (int start = 0; start < words.size(); ) {
            int count = words[start].size(), end;
            for (end = start + 1; end < words.size(); end++) {
                if (count + 1 + words[end].size() > maxWidth) break;
                else count += 1 + words[end].size();
            }
            string s = words[start];
            if (start + 1 == end || end == words.size()) {
                for (int i = start + 1; i < end; i++) {
                    s += ' ' + words[i];
                }
                s += string(maxWidth - s.size(), ' ');
            }
            else {
                int spaces = 1 + (maxWidth - count) / (end - start - 1);
                int extraSpaces = (maxWidth - count) % (end - start - 1);
                for (int i = start + 1; i < end; i++) {
                    int numSpaces = spaces + (i - start - 1 < extraSpaces);
                    s += string(numSpaces, ' ') + words[i];
                }
            }
            res.push_back(s);
            start = end;
        }
        return res;
    }
};