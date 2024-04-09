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
    bool helper(TreeNode* cur, TreeNode* min, TreeNode* max) {
        if (cur == NULL) return true;
        if (min != NULL && cur->val <= min->val) return false;
        if (max != NULL && cur->val >= max->val) return false;
        return helper(cur->left, min, cur) && helper(cur->right, cur, max);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
};