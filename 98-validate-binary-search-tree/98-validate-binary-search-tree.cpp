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
    bool fn(TreeNode* root,long int lmax,long int rmax)
    {
        if(!root) return 1;
        if(root->val<=lmax or root->val>=rmax) return 0;
        
        return fn(root->left,lmax,root->val) and fn(root->right,root->val,rmax);
    }
    bool isValidBST(TreeNode* root) {
        return fn(root,LONG_MIN,LONG_MAX);
    }
};