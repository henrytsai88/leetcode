class Solution {
public:
    int passThePillow(int n, int time) {
        int dir = time / (n - 1), offset = time % (n - 1);
        return dir % 2 == 0 ? 1 + offset : n - offset;
    }
};