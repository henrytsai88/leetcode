class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        int maxCount = 0, numOfMaxTasks = 0;
        for (char task : tasks) {
            if (++count[task - 'A'] > maxCount) {
                maxCount = count[task - 'A'];
                numOfMaxTasks = 1;
            }
            else if (count[task - 'A'] == maxCount) numOfMaxTasks++;
        }
        int res = (maxCount - 1) * (n + 1) + numOfMaxTasks;
        return max(res, (int) tasks.size());
    }
};