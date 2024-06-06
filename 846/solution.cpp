class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> m;
        for (int card : hand) m[card]++;
        for (auto p : m) {
            if (p.second > 0) {
                for (int i = 1; i < groupSize; i++) {
                    if (m[p.first + i] < p.second) return false;
                    m[p.first + i] -= p.second;
                }
            }
        }
        return true;
    }
};