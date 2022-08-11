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
    bool fn(TreeNode* root,long low,long high)
    {
        if(!root) return 1;
        
        if(root->val<=low or root->val>=high) return 0;
        
        
        bool l=fn(root->left,low,root->val);
        bool r=fn(root->right,root->val,high);
                 
        return l and r;
    }
    bool isValidBST(TreeNode* root) {
        return fn(root,LONG_MIN,LONG_MAX);
    }
};