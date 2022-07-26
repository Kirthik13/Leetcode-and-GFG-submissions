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
        
        if(p==root)
        {
            return root;
        }
        if(q==root)
        {
            return root;
        }
        
        TreeNode* lt=fn(root->left,p,q);
        TreeNode* rt=fn(root->right,p,q);
        if(lt and rt) return root;
        
        if(lt and !rt) return lt;
        if(rt and !lt) return rt;
        
        
        return NULL;
        
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      
        return fn(root,p,q);  
        
    }
};