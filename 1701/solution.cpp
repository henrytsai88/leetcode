class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double time = 0, waitingTime = 0;
        for (vector<int>& customer : customers) {
            time = max(time, (double) customer[0]) + customer[1];
            waitingTime += time - customer[0];
        }
        return waitingTime / customers.size();
    }
};