class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> res(3, false);
        for (vector<int>& triplet : triplets) {
            if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]) continue;
            for (int i = 0; i < 3; i++) {
                if (triplet[i] == target[i]) res[i] = true;
            }
        }
        return res[0] && res[1] && res[2];
    }
};