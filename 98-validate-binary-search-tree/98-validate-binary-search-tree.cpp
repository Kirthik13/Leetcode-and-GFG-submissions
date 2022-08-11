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
    bool fn(TreeNode* root,long l,long r)
    {
        if(!root) return 1;
        
        if(root->val<=l or root->val>=r) return 0;
        
        return fn(root->right,root->val,r) and fn(root->left,l,root->val);
    }
    bool isValidBST(TreeNode* root) {
     return fn(root,LONG_MIN,LONG_MAX);
    }
};