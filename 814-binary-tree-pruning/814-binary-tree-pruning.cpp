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
    bool fn(TreeNode* root)
    {
        if(!root) return 0;
        
        
        bool l=fn(root->left);
        bool r=fn(root->right);
        if(!l) root->left=NULL;
        if(!r) root->right=NULL;
        
        if(root->val!=1 and !r and !l) return 0;   
        return 1;
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!fn(root)) return NULL;
        return root;
    }
};