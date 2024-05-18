class TrieNode {
public:
    vector<TrieNode*> children;
    string word;
    TrieNode() {
        children = vector<TrieNode*>(26, NULL);
        word = "";
    }
};

class Solution {
public:
    int m, n;
    vector<string> res;
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string word : words) {
            TrieNode* cur = root;
            for (char c : word) {
                if (cur->children[c - 'a'] == NULL) {
                    cur->children[c - 'a'] = new TrieNode();
                }
                cur = cur->children[c - 'a'];
            }
            cur->word = word;
        }
        return root;
    }
    void dfs(vector<vector<char>>& board, TrieNode* node, int i, int j) {
        if (board[i][j] < 0) return;
        node = node->children[board[i][j] - 'a'];
        if (node == NULL) return;
        if (node->word != "") {
            res.push_back(node->word);
            node->word = "";
        }
        board[i][j] ^= 128;
        if (i > 0) dfs(board, node, i - 1, j);
        if (i < m - 1) dfs(board, node, i + 1, j);
        if (j > 0) dfs(board, node, i, j - 1);
        if (j < n - 1) dfs(board, node, i, j + 1);
        board[i][j] ^= 128;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(), n = board[0].size();
        TrieNode* root = buildTrie(words);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, root, i, j);
            }
        }
        return res;
    }
};