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
      bool fn(TreeNode* root,long long int min,long long int max)
    {
        if(!root) return 1;
        
        if(root->val>=max or root->val<=min) return 0;
        
        return fn(root->left,min,root->val) and fn(root->right,root->val,max);
        
        
    }
    bool isValidBST(TreeNode* root) {
        if(!root->left and !root->right) return 1;
        return fn(root,LONG_MIN,LONG_MAX);
    }
};