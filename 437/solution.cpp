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
    void helper(TreeNode* root, int targetSum, vector<long int>& v, int& res) {
        if (root == NULL) return;
        long int prefixSum = v.empty() ? root->val : v.back() + root->val;
        for (long int i : v) {
            if (prefixSum - i == targetSum) res++;
        }
        v.push_back(prefixSum);
        helper(root->left, targetSum, v, res);
        helper(root->right, targetSum, v, res);
        v.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        int res = 0;
        vector<long int> v(1, 0);
        helper(root, targetSum, v, res);
        return res;
    }
};