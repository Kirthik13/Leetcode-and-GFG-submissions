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
    TreeNode* fn(TreeNode* root, int val)
    {
        if(!root)
        {
            TreeNode* h=new TreeNode(val);
            return h;
        }
        
        if(root->val > val)
        {
            root->left=fn(root->left,val);
        }
        if(root->val < val)
        {
            root->right=fn(root->right,val);
        }
        return root;
            
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        return fn(root,val);
    }
};