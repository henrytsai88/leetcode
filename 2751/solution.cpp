class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> index(n), stack, res;
        for (int i = 0; i < n; i++) index[i] = i;
        sort(index.begin(), index.end(), [&] (const int& p, const int& q) {
            return positions[p] < positions[q];
        });
        for (int i : index) {
            if (directions[i] == 'R') {
                stack.push_back(i);
            }
            else {
                while (!stack.empty() && healths[i] > 0) {
                    if (healths[stack.back()] < healths[i]) {
                        healths[stack.back()] = 0, stack.pop_back();
                        healths[i]--;
                    }
                    else if (healths[stack.back()] > healths[i]) {
                        healths[stack.back()]--;
                        healths[i] = 0;
                    }
                    else {
                        healths[stack.back()] = 0, stack.pop_back();
                        healths[i] = 0;
                    }
                }
            }
        }
        for (int health : healths) {
            if (health) res.push_back(health);
        }
        return res;
    }
};