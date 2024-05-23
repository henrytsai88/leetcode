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
    void reversePreorder(TreeNode* root, TreeNode*& prev) {
        if (root == NULL) return;
        reversePreorder(root->right, prev);
        reversePreorder(root->left, prev);
        root->left = NULL;
        root->right = prev;
        prev = root;
    }
    void flatten(TreeNode* root) {
        TreeNode* prev = NULL;
        reversePreorder(root, prev);
    }
};