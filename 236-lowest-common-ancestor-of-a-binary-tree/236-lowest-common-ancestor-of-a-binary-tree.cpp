/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
        {
            return NULL;
        }
        if(root->left==p and root->right==q)
        {
            return root;
        }
        if(root==p or root==q) return root;
        TreeNode* ll=lowestCommonAncestor(root->left,p,q);
        TreeNode* lr=lowestCommonAncestor(root->right,p,q);
        if(ll and lr)
        {
            return root;
        }
        if(ll) return ll;
        if(lr) return lr;
        return NULL;

    }
};