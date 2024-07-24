class Solution {
public:
    int mapper(int num, vector<int>& mapping) {
        int res = 0;
        string s = to_string(num);
        for (char c : s) res = res * 10 + mapping[c - '0'];
        return res;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({mapper(nums[i], mapping), i});
        }
        sort(v.begin(), v.end());
        vector<int> res;
        for (pair<int, int>& p : v) {
            res.push_back(nums[p.second]);
        }
        return res;
    }
};