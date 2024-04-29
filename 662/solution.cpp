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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int res = 0;
        while (!q.empty()) {
            int size = q.size(), width = q.back().second - q.front().second + 1;
            res = max(res, width);
            for (int i = 0; i < size; i++) {
                pair<TreeNode*, unsigned long long> p = q.front(); q.pop();
                if (p.first->left) q.push({p.first->left, 2 * p.second});
                if (p.first->right) q.push({p.first->right, 2 * p.second + 1});
            }
        }
        return res;
    }
};