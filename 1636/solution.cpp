class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int num : nums) m[num]++;
        vector<pair<int, int>> v;
        for (auto p : m) v.push_back(p);
        sort(v.begin(), v.end(), [] (const auto& p, const auto& q) {
            if (p.second == q.second) return p.first > q.first;
            return p.second < q.second;
        });
        vector<int> res;
        for (auto p : v) {
            while (p.second--) {
                res.push_back(p.first);
            }
        }
        return res;
    }
};