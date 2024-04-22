class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, totalAmount = 0, amount = 0;
        for (int i = 0; i < gas.size(); i++) {
            totalAmount += gas[i] - cost[i];
            amount += gas[i] - cost[i];
            if (amount < 0) {
                start = i + 1;
                amount = 0;
            }
        }
        return totalAmount < 0 ? -1 : start;
    }
};