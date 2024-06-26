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
    void helper(TreeNode* root, int& k, int& res) {
        if (root == NULL) return;
        helper(root->left, k, res);
        if (!--k) {
            res = root->val;
            return;
        }
        helper(root->right, k, res);
    }
    int kthSmallest(TreeNode* root, int k) {
        int res;
        helper(root, k, res);
        return res;
    }
};