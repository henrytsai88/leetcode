class Solution {
public:
    struct compare {
        bool operator() (const auto& p, const auto& q) {
            return p[0] > q[0];
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = min((int) nums1.size(), k), n = min((int) nums2.size(), k);
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        for (int i = 0; i < m; i++) pq.push({nums1[i] + nums2[0], i, 0});
        vector<vector<int>> res;
        while (k-- && !pq.empty()) {
            vector<int> cur = pq.top(); pq.pop();
            int sum = cur[0], i = cur[1], j = cur[2];
            res.push_back({nums1[i], nums2[j]});
            if (++j < n) {
                pq.push({nums1[i] + nums2[j], i, j});
            }
        }
        return res;
    }
};