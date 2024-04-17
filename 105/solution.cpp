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
    TreeNode* helper(vector<int>& preorder, int left, int right, int& i, map<int, int>& m) {
        if (left > right) return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);
        int j = m[root->val];
        root->left = helper(preorder, left, j - 1, i, m);
        root->right = helper(preorder, j + 1, right, i, m);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> m;
        for (int i = 0; i < inorder.size(); i++) m[inorder[i]] = i;
        int i = 0;
        return helper(preorder, 0, inorder.size() - 1, i, m);
    }
};