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
    int fn(TreeNode* root,int &ans)
    {
        if(!root) return 0;
        
        int lsum=fn(root->left,ans);
        int rsum=fn(root->right,ans);
        
        if(lsum<0) lsum=0;
        if(rsum<0) rsum=0;

        
        ans=max(root->val+lsum+rsum,ans);
        
        return root->val+max(lsum,rsum);

    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int ans=INT_MIN;
        int g=fn(root,ans);   
        return ans;
    }
};