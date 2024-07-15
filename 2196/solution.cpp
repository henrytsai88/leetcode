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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> getNode;
        unordered_set<int> isChild;
        for (vector<int>& d : descriptions) {
            if (!getNode.count(d[0])) getNode[d[0]] = new TreeNode(d[0]);
            if (!getNode.count(d[1])) getNode[d[1]] = new TreeNode(d[1]);
            if (d[2] == 1) getNode[d[0]]->left = getNode[d[1]];
            else getNode[d[0]]->right = getNode[d[1]];
            isChild.insert(d[1]);
        }
        for (vector<int>& d : descriptions) {
            if (!isChild.count(d[0])) return getNode[d[0]];
        }
        return NULL;
    }
};