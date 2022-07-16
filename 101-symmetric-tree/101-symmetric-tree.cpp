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
    bool fn(TreeNode* p,TreeNode* q)
    {
        if(!p and !q) return 1;
        if(!p) return 0;
        if(!q) return 0;
        
        if(p->val!=q->val) return 0;
        bool lt=fn(p->left,q->right);
        bool rt=fn(p->right,q->left);
        
        if(!lt or !rt) return 0;
        
        return 1;

    }
    bool isSymmetric(TreeNode* root) {
        
        if(!root) return 1;
        return fn(root,root);
    }
};