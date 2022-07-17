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
    TreeNode* fn(TreeNode* root)
    {
        if(!root) return NULL;
        TreeNode* lnode=fn(root->left);
        TreeNode* rnode=fn(root->right);
      
        if(lnode and rnode)
        {
            
            root->right=lnode;
            root->left=NULL;
            while(lnode->right!=NULL)
            {
                lnode=lnode->right;
            }
           
            
            lnode->right=rnode;
             
            
            
        }
        else if(lnode)
        {
            // cout<<lnode->val<<endl;
            root->right=lnode;
            root->left=NULL;
        }
       
               
        
        return root;
        
        
        
    }
    void flatten(TreeNode* root) {
        
        TreeNode* g=fn(root);
        
        
    }
};