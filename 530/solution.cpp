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
    void inorder(TreeNode* root, TreeNode*& prev, int& res) {
        if (!root) return;
        inorder(root->left, prev, res);
        if (prev) {
            res = min(res, abs(root->val - prev->val));
        }
        prev = root;
        inorder(root->right, prev, res);
    }
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        TreeNode* prev = NULL;
        inorder(root, prev, res);
        return res;
    }
};