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
    TreeNode* helper(vector<int>& postorder, int left, int right, int& i, unordered_map<int, int>& m) {
        if (left > right) return NULL;
        TreeNode* root = new TreeNode(postorder[i--]);
        int j = m[root->val];
        root->right = helper(postorder, j + 1, right, i, m);
        root->left = helper(postorder, left, j - 1, i, m);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); i++) m[inorder[i]] = i;
        int i = postorder.size() - 1;
        return helper(postorder, 0, inorder.size() - 1, i, m);
    }
};