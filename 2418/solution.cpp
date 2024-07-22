class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int> index(n);
        for (int i = 0; i < n; i++) index[i] = i;
        sort(index.begin(), index.end(), [&] (const auto& p, const auto& q) {
            return heights[p] > heights[q];
        });
        vector<string> res(n);
        for (int i = 0; i < n; i++) res[i] = names[index[i]];
        return res;
    }
};