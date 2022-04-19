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
    void fn1(TreeNode* root,multiset<int>&v)
    {
        if(!root) return;
        
        fn1(root->left,v);
        v.insert(root->val);
        fn1(root->right,v);

            
    }
    void fn2(TreeNode* &root,multiset<int>&v)
    {
        if(!root) return;
        
        fn2(root->left,v);
        
        root->val=*v.begin();
        v.erase(v.begin());
        fn2(root->right,v);
    }
    void recoverTree(TreeNode* root) {
        multiset<int>v;
        fn1(root,v);
        fn2(root,v);

    }
};