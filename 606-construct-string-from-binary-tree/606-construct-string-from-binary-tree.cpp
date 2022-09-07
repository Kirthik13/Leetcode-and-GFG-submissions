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
    void fn(TreeNode* root,string &s) 
    {
        if(!root) return ;
//         if(!root->left and !root->right)
//         {
            
//             return ;
//         }
        
        
        // char ch=char(root->val)+'0';
        
        // stringstream ss();
        string ch=to_string(root->val);
        // ss>>ch;
        s+=ch;
        
        if(root->left and root->right)
        {
            s.push_back('(');
            fn(root->left,s);
            s.push_back(')');
            s.push_back('(');            
            fn(root->right,s);
            s.push_back(')');
            
            
        }
        else if(root->left)
        {
            s.push_back('(');
            fn(root->left,s);            
            s.push_back(')');
            
        }
         else if(root->right)
        {
            s.push_back('(');
            s.push_back(')');
             
            s.push_back('(');
            fn(root->right,s);            
            s.push_back(')');
            
        }
       
        
    }
    string tree2str(TreeNode* root) {
        string s;
        fn(root,s);
        return s;
    }
};