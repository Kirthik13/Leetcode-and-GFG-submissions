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
    TreeNode* fn(TreeNode* org, TreeNode* root, TreeNode* target)
    {
        if(!root) return NULL;
        
        if(root->val==target->val) return root;
        TreeNode* l=fn(org,root->left,target);
        TreeNode* r=fn(org,root->right,target);

        if(l) return l;
        if(r) return r;
        return NULL;
    }
    TreeNode* getTargetCopy(TreeNode* org, TreeNode* cl, TreeNode* target) {
       return fn(org,cl,target);
    }
};