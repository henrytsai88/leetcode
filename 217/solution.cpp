class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            if (freq.count(num)) return true;
            freq[num]++;
        }
        return false;
    }
};