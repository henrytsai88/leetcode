class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (int i = 0; i < asteroids.size(); ) {
            if (!res.empty() && res.back() > 0 && asteroids[i] < 0) {
                if (res.back() == -asteroids[i]) {
                    res.pop_back();
                    i++;
                }
                else if (res.back() < -asteroids[i]) res.pop_back();
                else i++;
            }
            else res.push_back(asteroids[i++]);
        }
        return res;
    }
};