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
    TreeNode* helper(TreeNode* root, bool is_root, unordered_set<int>& s, vector<TreeNode*>& res) {
        if (root == NULL) return NULL;
        bool deleted = s.count(root->val);
        if (is_root && !deleted) res.push_back(root);
        root->left = helper(root->left, deleted, s, res);
        root->right = helper(root->right, deleted, s, res);
        return deleted ? NULL : root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> s(to_delete.begin(), to_delete.end());
        helper(root, true, s, res);
        return res;
    }
};