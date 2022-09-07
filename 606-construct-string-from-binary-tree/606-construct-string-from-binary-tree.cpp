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
    string fn(TreeNode* root) 
    {
        if(!root) return "";

        
        
        string ch=to_string(root->val);
        
        if(root->left and root->right)
        {
            ch+=('('+fn(root->left)+')');

            ch+=('('+fn(root->right)+')');
            
            
        }
        else if(root->left)
        {
            ch+=('('+fn(root->left)+')');            
            
        }
         else if(root->right)
        {
            
                    ch+=("()");            

            ch+=('('+fn(root->right)+')');
             
            
        }
        
        return ch;
       
        
    }
    string tree2str(TreeNode* root) {
    return fn(root);
    }
};