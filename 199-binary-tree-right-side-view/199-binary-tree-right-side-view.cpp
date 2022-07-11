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
    void fn(TreeNode* root,int level, vector<int>&tot)
    {
        if(!root) return;
        if(tot.size()<level) tot.push_back(root->val);
        fn(root->right,level+1,tot);
        fn(root->left,level+1,tot);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>tot;
        fn(root,1,tot);
        return tot;
    }
};