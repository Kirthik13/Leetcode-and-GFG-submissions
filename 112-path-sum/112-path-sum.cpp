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
    bool fn(TreeNode* root, int &k,int sum) 
    {
        if(!root) return 0;
        if(!root->left and !root->right)
        {
            if(sum+root->val==k) return 1;
                return 0;
        }
        
        if(fn(root->left,k,sum+root->val)) return 1;
        if(fn(root->right,k,sum+root->val)) return 1;
        
        return 0;
        
    }
    bool hasPathSum(TreeNode* root, int k) {
    
        return fn(root,k,0);
    }
};