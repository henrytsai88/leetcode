class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for (int num : s) {
            if (!s.count(num - 1)) {
                int start = num, end = num + 1;
                while (s.count(end)) end++;
                res = max(res, end - start);
            }
        }
        return res;
    }
};