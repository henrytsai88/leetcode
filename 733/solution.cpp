class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size(), c = image[0].size(), oldColor = image[sr][sc];
        queue<pair<int, int>> q;
        q.push(pair<int, int>(sr, sc));
        while (!q.empty()) {
            pair<int, int> cur = q.front(); q.pop();
            if (cur.first < 0 || cur.first >= r || cur.second < 0 || cur.second >= c) continue;
            if (image[cur.first][cur.second] != oldColor || image[cur.first][cur.second] == color) continue;
            image[cur.first][cur.second] = color;
            q.push(pair<int, int>(cur.first + 1, cur.second));
            q.push(pair<int, int>(cur.first - 1, cur.second));
            q.push(pair<int, int>(cur.first, cur.second + 1));
            q.push(pair<int, int>(cur.first, cur.second - 1));
        }
        return image;
    }
};