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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        return fun(sum, root);
    }
    TreeNode* fun(int &sum, TreeNode* root) {
        if (!root)
            return nullptr;
        fun(sum, root->right);
        sum += root->val;
        root->val = sum;
        fun(sum, root->left);
        return root;
    }
};