class DetectSquares {
private:
    map<pair<int, int>, int> m;
public:
    DetectSquares() {}
    
    void add(vector<int> point) {
        m[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        for (auto p : m) {
            int x = p.first.first, y = p.first.second, freq = p.second;
            if (x == point[0] && y != point[1]) {
                int length = abs(y - point[1]);
                res += m[{x - length, y}] * m[{x - length, point[1]}] * freq;
                res += m[{x + length, y}] * m[{x + length, point[1]}] * freq;
            }
        }
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */