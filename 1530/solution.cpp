/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> dfs(TreeNode* root, int distance, int& res) {
        if (root == NULL) return vector<int>(distance + 1, 0);
        vector<int> count(distance + 1, 0);
        if (root->left == NULL && root->right == NULL) {
            count[1] = 1;
            return count;
        }
        vector<int> left = dfs(root->left, distance, res);
        vector<int> right = dfs(root->right, distance, res);
        for (int l = 1; l <= distance; l++) {
            for (int r = 1; r <= distance; r++) {
                if (l + r > distance) break;
                res += left[l] * right[r];
            }
        }
        for (int i = 0; i < distance; i++) {
            count[i + 1] = left[i] + right[i];
        }
        return count;
    }
    int countPairs(TreeNode* root, int distance) {
        int res = 0;
        vector<int> count = dfs(root, distance, res);
        return res;
    }
};