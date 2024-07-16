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
    bool find(TreeNode* root, int val, string& path) {
        if (root == NULL) return false;
        if (root->val == val) return true;
        if (find(root->left, val, path)) path.push_back('L');
        else if (find(root->right, val, path)) path.push_back('R');
        return !path.empty();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s, t;
        find(root, startValue, s);
        find(root, destValue, t);
        while (s.size() && t.size() && s.back() == t.back()) {
            s.pop_back();
            t.pop_back();
        }
        reverse(t.begin(), t.end());
        return string(s.size(), 'U') + t;
    }
};