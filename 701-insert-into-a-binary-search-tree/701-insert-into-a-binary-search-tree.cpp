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
   TreeNode* fn(TreeNode* node,int k)
    {
        if(!node)
        {
               // else{
        TreeNode *newnode=new TreeNode(k);
        return newnode;
        }
            // return NULL;
        // }
        
        if(node->val > k)
        {
           node->left= fn(node->left,k);
        }
        else if(node->val < k){
            node->right=fn(node->right,k);
        }
     
        return node;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
        {
            TreeNode *newnode=new TreeNode(val);
            return newnode;
        }
        return fn(root,val);
    }
};