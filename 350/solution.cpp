class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_multiset<int> s(nums1.begin(), nums1.end());
        vector<int> res;
        for (int num : nums2) {
            auto it = s.find(num);
            if (it == s.end()) continue;
            res.push_back(*it);
            s.erase(it);
        }
        return res;
    }
};