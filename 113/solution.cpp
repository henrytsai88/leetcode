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
    void helper(TreeNode* root, int targetSum, vector<int>& v, vector<vector<int>>& res) {
        if (root == NULL) return;
        v.push_back(root->val);
        if (root->left == NULL && root->right == NULL && targetSum - root->val == 0) res.push_back(v);
        helper(root->left, targetSum - root->val, v, res);
        helper(root->right, targetSum - root->val, v, res);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> v;
        helper(root, targetSum, v, res);
        return res;
    }
};