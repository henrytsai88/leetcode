class Solution {
public:
    struct compare {
        bool operator() (const auto& p, const auto& q) {
            return p.first > q.first;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> pq;
        int right = nums[0][0];
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], {i, 0}});
            right = max(right, nums[i][0]);
        }
        vector<int> res;
        while (pq.size() == nums.size()) {
            auto [left, p] = pq.top(); pq.pop();
            int i = p.first, j = p.second;
            if (res.empty() || right - left < res[1] - res[0]) {
                res = {left, right};
            }
            if (++j < nums[i].size()) {
                right = max(right, nums[i][j]);
                pq.push({nums[i][j], {i, j}});
            }
        }
        return res;
    }
};