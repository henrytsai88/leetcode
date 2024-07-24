class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int res = 0;
        unordered_set<string> bankSet(bank.begin(), bank.end());
        vector<char> bases = {'A', 'C', 'G', 'T'};
        queue<string> q;
        q.push(startGene);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string cur = q.front(); q.pop();
                if (cur == endGene) return res;
                for (int i = 0; i < 8; i++) {
                    char tmp = cur[i];
                    for (char c : bases) {
                        cur[i] = c;
                        if (bankSet.count(cur)) {
                            bankSet.erase(cur);
                            q.push(cur);
                        }
                    }
                    cur[i] = tmp;
                }
            }
            res++;
        }
        return -1;
    }
};