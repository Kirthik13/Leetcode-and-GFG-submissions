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
    TreeNode* fn(TreeNode* root,int key)
    {
        if(!root) return NULL;
        if(root->val==key)
        {
               if(!root->left)
                {
                    return root->right;
                }
                else if(!root->right)
                {
                    return root->left;
                }
                else{
                    TreeNode* nextnode=root->right;
                    
                    while(nextnode->left!=NULL)
                    {
                        nextnode=nextnode->left;
                    }
                    nextnode->left=root->left;
                    return root->right;
                }
        }
        if(root->val>key)
        {
            root->left=fn(root->left,key);
        }
        if(root->val<key)
        {
           root->right= fn(root->right,key);

        }
        
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return fn(root,key);
    }
};