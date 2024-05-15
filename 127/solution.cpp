class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end()), visited;
        queue<string> q;
        q.push(beginWord);
        int changes = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string cur = q.front(); q.pop();
                if (cur == endWord) return changes;
                for (int i = 0; i < beginWord.size(); i++) {
                    char tmp = cur[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        cur[i] = c;
                        if (wordSet.count(cur) && !visited.count(cur)) {
                            q.push(cur);
                            visited.insert(cur);
                        }
                    }
                    cur[i] = tmp;
                }
            }
            changes++;
        }
        return 0;
    }
};