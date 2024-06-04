class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int pre2 = cost[0], pre = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            int cur = cost[i] + min(pre, pre2);
            pre2 = pre;
            pre = cur;
        }
        return min(pre, pre2);
    }
};