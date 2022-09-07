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
    string fn(TreeNode* root,string &s) 
    {
        if(!root) return "";

        
        
        string ch=to_string(root->val);
        
        if(root->left and root->right)
        {
            // s.push_back('(');
            ch+=('('+fn(root->left,s)+')');
            // s.push_back(')');
            // s.push_back('(');            
            ch+=('('+fn(root->right,s)+')');
            // s.push_back(')');
            
            
        }
        else if(root->left)
        {
            // s.push_back('(');
            ch+=('('+fn(root->left,s)+')');            
            // s.push_back(')');
            
        }
         else if(root->right)
        {
            // s.push_back('(');
            // s.push_back(')');
                    ch+=("()");            

            // s.push_back('(');
            // fn(root->right,s);            
            // s.push_back(')');
            ch+=('('+fn(root->right,s)+')');
             
            
        }
        
        return ch;
       
        
    }
    string tree2str(TreeNode* root) {
        string s;
    return fn(root,s);
        // return s;
    }
};