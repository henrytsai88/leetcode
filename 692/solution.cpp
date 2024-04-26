class Solution {
public:
    struct compare {
        bool operator() (const auto& p, const auto& q) {
            if (p.second == q.second) return p.first < q.first;
            return p.second > q.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        for (string word : words) m[word]++;
        priority_queue<pair<string, int>, vector<pair<string, int>>, compare> pq;
        for (auto it = m.begin(); it != m.end(); it++) {
            pq.push({it->first, it->second});
            if (pq.size() > k) pq.pop();
        }
        vector<string> res(k);
        while (k--) {
            pair<string, int> p = pq.top(); pq.pop();
            res[k] = p.first;
        }
        return res;
    }
};