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
//     int fn(TreeNode* root,bool &flag)
//     {
//         if(!root) return 0;
//         if(!flag) return 0;
        
//         int hl=fn(root->left,flag);
//         int hr=fn(root->right,flag);
        
//         if(abs(hl-hr)>1) flag=false;
        
//         return 1+max(hl,hr);
 
//     }
    int fn(TreeNode* root)
    {
        if(!root) return 0;
        
        int hl=fn(root->left);
        int hr=fn(root->right);
        
        if(abs(hl-hr)>1) return -1;
        
        if(hl==-1 or hr==-1) return -1;
        
        return 1+max(hl,hr);
 
    }
    bool isBalanced(TreeNode* root) {
        // bool flag=true;
        int g=fn(root);
        return g==-1?false:true;
    }
};