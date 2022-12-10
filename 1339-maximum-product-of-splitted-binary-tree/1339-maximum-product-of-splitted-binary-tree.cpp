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
#define  mod 1000000007
class Solution {
public:
    long int totans=0;
    long int res{};
    long int fn(TreeNode* root) 
    {
        if(!root)
        {
            
            
            return 0;
        }
        
       long int l= fn(root->left);
        
        long int r=fn(root->right);
        long int sub=root->val+l+r;
       res=max(res,(sub*(totans-sub)));
        
        return sub;
    }
    int maxProduct(TreeNode* root) {
        
        totans=fn(root);
        fn(root);
        return res%(int)mod;
    }
};