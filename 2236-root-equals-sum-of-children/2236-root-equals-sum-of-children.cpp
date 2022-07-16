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
    int fn(TreeNode* root,int &flag)
    {
        if(!root->left and !root->right) return root->val;
        
        int lt=fn(root->left,flag);
        int rt=fn(root->right,flag);
        
        if(lt+rt!=root->val)
        {
            flag=0;
            return 0;

        }
        return root->val;
    }
    bool checkTree(TreeNode* root) {
        int flag=1;
        int g=fn(root,flag);
        return flag;
    }
};