class Solution {
public:
    int pos(vector<vector<int>>& board, int cur, int n) {
        int i = cur / n, j = cur % n;
        if (i % 2 == 1) j = n - 1 - j;
        i = n - 1 - i;
        return board[i][j];
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), res = 0;
        vector<bool> visited(n * n, false);
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int cur = q.front(); q.pop();
                if (cur == n * n) return res;
                if (visited[cur]) continue;
                visited[cur] = true;
                for (int i = 1; i <= 6 && cur + i <= n * n; i++) {
                    int next = cur + i;
                    int nextPos = pos(board, next - 1, n);
                    if (nextPos != -1) next = nextPos;
                    q.push(next);
                }
            }
            res++;
        }
        return -1;
    }
};