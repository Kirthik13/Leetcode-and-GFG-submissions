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
    int idx{};
    TreeNode* bstFromPreorder(vector<int>& pre,int par=INT_MAX) {
        if(idx==pre.size() or par<pre[idx])  return NULL;
        
        TreeNode* root=new TreeNode(pre[idx]);
        int currpar=pre[idx];
        idx++;
        root->left=bstFromPreorder(pre,currpar);
        root->right=bstFromPreorder(pre,par);
        
        return root;
        
    }
};