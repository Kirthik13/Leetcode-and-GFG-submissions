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
    TreeNode* fn(TreeNode* root, int k)
    {
        if(!root) return NULL;
        if(root->val==k)
        {
            if(!root->left) return root->right;
            if(!root->right) return root->left;
            
            TreeNode* rn=root->right;
            while(rn->left)
            {
                rn=rn->left;
            }
            rn->left=root->left;
            return root->right;
            
        }
        else if(root->val < k)
        {
            root->right=fn(root->right,k);
        }
        else if(root->val > k)
        {
            root->left=fn(root->left,k);
            
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int k) {
     return fn(root,k);   
    }
};