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
    int fn(TreeNode* root) 
    {
        int cl{},cr{};
        TreeNode* l=root;
        TreeNode* r=root;
        
        while(l)
        {
            cl++;
            l=l->left;
        }
        
        while(r)
        {
            cr++;
            r=r->right;
        }
        
        if(cl==cr) return pow(2,cl)-1;
        
        return 1+fn(root->left)+fn(root->right);
        
        
    }
    int countNodes(TreeNode* root) {
        return fn(root);
    }
};