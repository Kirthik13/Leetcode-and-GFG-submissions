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
    TreeNode* fn(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root) return NULL;
        if((root->left==p and root->right==q) or (root->left==q and root->right==p)) return root;

        if(root->val==p->val or root->val==q->val )
        {
            if(root->val==p->val)
            {
                if(p->val < q->val or p->val > q->val) return p;
            }
             if(root->val==q->val)
            {
                if(q->val < p->val or q->val > p->val) return q;
            } 
        }
        
        TreeNode* ln=fn(root->left,p,q);
        TreeNode* rn=fn(root->right,p,q);
        
        if(ln and rn) return root;
        if(ln) return ln;
        if(rn) return rn;
        
        return NULL;
        
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return fn(root,p,q);
    }
};