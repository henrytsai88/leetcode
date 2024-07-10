class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;
        for (string& log : logs) {
            if (log == "../") res = max(res - 1, 0);
            else if (log == "./") continue;
            else res++;
        }
        return res;
    }
};