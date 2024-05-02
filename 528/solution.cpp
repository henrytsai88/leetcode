class Solution {
private:
    vector<int> v;
public:
    Solution(vector<int>& w) {
        for (int i : w) v.push_back(v.empty() ? i : v.back() + i);
    }
    
    int pickIndex() {
        int val = rand() % v.back();
        auto it = upper_bound(v.begin(), v.end(), val);
        return it - v.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */