class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size(), satisfied = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0 || i < minutes) satisfied += customers[i];
        }
        int res = satisfied;
        for (int i = minutes; i < n; i++) {
            if (grumpy[i] == 1) satisfied += customers[i];
            if (grumpy[i - minutes] == 1) satisfied -= customers[i - minutes];
            res = max(res, satisfied);
        }
        return res;
    }
};