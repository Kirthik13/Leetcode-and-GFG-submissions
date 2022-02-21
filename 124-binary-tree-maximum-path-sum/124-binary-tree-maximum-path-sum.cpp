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
    int ans=INT_MIN;
    int fn(TreeNode* root)
    {
        if(!root) return 0;
        
        int l=fn(root->left);
        int r=fn(root->right);
        
        ans=max(ans,max(max(max(root->val+l,root->val+r),root->val+l+r),root->val));
        return max(root->val+max(l,r),root->val);

    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        if(!root->right and !root->left) return root->val;
       int g=fn(root);
        return ans;
    }
};