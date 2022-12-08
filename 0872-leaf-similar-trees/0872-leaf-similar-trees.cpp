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
    void fn(TreeNode* root, vector<int>&v)
    {
        if(!root)
        {
            return;
            
        }
        
        if(!root->left and !root->right)
        {
            v.push_back(root->val);
        }
        
        fn(root->left,v);
        fn(root->right,v);
        
        
    }
    bool leafSimilar(TreeNode* r1, TreeNode* r2) {
        vector<int>v1,v2;
        fn(r1,v1);
        fn(r2,v2);
        
        return v1==v2;
        
    }
};