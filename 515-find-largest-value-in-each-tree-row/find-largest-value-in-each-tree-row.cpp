/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> sol;
    void travel(TreeNode* root, int level) {
        if (!root) {
            return;
        }
        if (sol.size() == level) {
            sol.push_back(root->val);
        } else {
            sol[level] = max(sol[level], root->val);
        }
        travel(root->left, level + 1);
        travel(root->right, level + 1);
    }

    vector<int> largestValues(TreeNode* root) {
        travel(root, 0);

        return sol;
    }
};