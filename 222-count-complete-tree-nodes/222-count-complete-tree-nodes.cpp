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
        if(!root) return 0;
        
        TreeNode* l=root;
        TreeNode* r=root;
        
        int hl{},hr{};
        while(l)
        {
            hl++;
            l=l->left;
        }
        while(r)
        {
            hr++;
            r=r->right;
        }        
        
        if(hl==hr) return pow(2,hl)-1;
        return 1+fn(root->left)+fn(root->right);
        
        
    }
    int countNodes(TreeNode* root) {
        return fn(root);
    }
};