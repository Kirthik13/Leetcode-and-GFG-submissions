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
class nodeval
{
    public:
        int mini,maxi,maxsum;
        nodeval(int x,int y,int z)
        {
            mini=x;
            maxi=y;
            maxsum=z;
        }
};
class Solution {
public:
    int ans{};
    nodeval fn(TreeNode* root)
    {
        if(!root)
        {
            return {INT_MAX,INT_MIN,0};
        }
        
        nodeval ln=fn(root->left);
        nodeval rn=fn(root->right);
        
        if(ln.maxi<root->val and rn.mini>root->val)
        {
            // if(root->val==-5)
            // {
            //     cout<<ln.maxsum<<" "<<rn.maxsum<<endl;
            // }
            ans=max(ans,root->val+ln.maxsum+rn.maxsum);
            return {min(root->val,ln.mini),max(root->val,rn.maxi),ln.maxsum+rn.maxsum+root->val};
        }
            
        return {INT_MIN,INT_MAX,max(ln.maxsum,rn.maxsum)};
        
        
    }
    int maxSumBST(TreeNode* root) {
        int g=fn(root).maxsum;   
        return ans;
        // return g>0?g:0;
    }
};