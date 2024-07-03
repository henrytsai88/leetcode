class Solution {
public:
    int nextNumber(int n) {
        int sum = 0;
        while (n) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = nextNumber(slow);
            fast = nextNumber(fast);
            fast = nextNumber(fast);
            if (fast == 1) return true;
        } while (slow != fast);
        return false;
    }
};