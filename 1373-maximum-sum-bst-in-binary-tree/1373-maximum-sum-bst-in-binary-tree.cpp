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
    int ans{};
    int fn(TreeNode* root,int &mn,int &mx)
    {
        if(!root) return 0;
        int lmn,rmn,lmx,rmx;
     lmn=rmn=INT_MAX;
        lmx=rmx=INT_MIN;
        
        int ln=fn(root->left,lmn,lmx);
        int rn=fn(root->right,rmn,rmx);
    
        
        int value=root->val+ln+rn;
        
        if(lmx<root->val and rmn>root->val)
        {
            ans=max(ans,value);
            mx=max(rmx,root->val);
            mn=min(lmn,root->val);
            
        }
        else{
            mn=INT_MIN;
            mx=INT_MAX;
        }
        
        return value;
        
        
    }
    int maxSumBST(TreeNode* root) {
        int mn=INT_MIN,mx=INT_MAX;
         fn(root,mn,mx);
        return ans;
    }
};