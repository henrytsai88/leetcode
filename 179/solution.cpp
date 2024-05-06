class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for (int num : nums) v.push_back(to_string(num));
        sort(v.begin(), v.end(), [] (const auto& p, const auto& q) {
            return p + q > q + p;
        });
        string res;
        for (string s : v) res += s;
        while (res[0] == '0' && res.size() > 1) res.erase(0, 1);
        return res;
    }
};