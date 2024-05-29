class Solution {
public:
    struct compare {
        bool operator() (const auto& p, const auto& q) {
            return p.second > q.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for (int num : nums) m[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        for (auto p : m) {
            pq.push(p);
            if (pq.size() > k) pq.pop();
        }
        vector<int> res;
        while (k--) {
            res.push_back(pq.top().first); pq.pop();
        }
        return res;
    }
};