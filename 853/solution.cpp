class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, double> m;
        for (int i = 0; i < position.size(); i++) {
            m[-position[i]] = (double) (target - position[i]) / speed[i];
        }
        stack<double> s;
        for (auto p : m) {
            if (s.empty() || s.top() < p.second) s.push(p.second);
        }
        return s.size();
    }
};