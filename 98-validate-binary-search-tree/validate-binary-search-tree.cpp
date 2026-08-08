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
    bool val(TreeNode* r,long long int l,long long int h){
        if(r==NULL) return true;
        if(r->val>=h) return false;
        if(r->val<=l) return false;
        if(val(r->left,l,r->val)&&val(r->right,r->val,h)) return true;
        return false;
    }
    long long int low(TreeNode* r){
        if(r->left==NULL) return r->val;
        return low(r->left);
    }
    long long int high(TreeNode* r){
        if(r->right==NULL) return r->val;
        return high(r->right);
    }
    bool isValidBST(TreeNode* root) {
        return val(root,low(root)-1,high(root)+1);
    }
};