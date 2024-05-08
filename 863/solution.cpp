/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<TreeNode*, int> m;
public:
    int find(TreeNode* root, TreeNode* target) {
        if (root == NULL) return -1;
        if (root == target) {
            m[root] = 0;
            return 0;
        }
        int left = find(root->left, target);
        if (left >= 0) {
            m[root] = left + 1;
            return left + 1;
        }
        int right = find(root->right, target);
        if (right >= 0) {
            m[root] = right + 1;
            return right + 1;
        }
        return -1;
    }
    void dfs(TreeNode* root, int k, int dist, vector<int>& res) {
        if (root == NULL) return;
        if (m.count(root)) dist = m[root];
        if (dist == k) res.push_back(root->val);
        dfs(root->left, k, dist + 1, res);
        dfs(root->right, k, dist + 1, res);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        find(root, target);
        dfs(root, k, m[root], res);
        return res;
    }
};