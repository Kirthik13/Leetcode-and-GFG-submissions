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
        if(!root) return NULL;
        
        if(root==p) return root;
        if(root==q) return root;
        TreeNode* l=NULL;
        TreeNode* r=NULL;
        if(root->val>p->val or root->val>q->val)
        {
            l=lowestCommonAncestor(root->left,p,q);
            // if(l) return l;
        }
        if(root->val<p->val or root->val<q->val)
        {
            r=lowestCommonAncestor(root->right,p,q);
            // if(r) return r;
        }
        if(l and r) return root;
        if(l) return l;
        if(r) return r;
        return NULL;
            
    }
};