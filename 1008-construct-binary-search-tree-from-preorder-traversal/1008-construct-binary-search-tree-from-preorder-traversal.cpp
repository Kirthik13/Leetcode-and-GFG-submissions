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
    TreeNode* bstFromPreorder(vector<int>& v,int par=INT_MAX) {
     if(v.size()==idx or par<v[idx]) return NULL;
    
        int curval=v[idx];
        TreeNode* root=new TreeNode(v[idx++]);
        root->left=bstFromPreorder(v,curval);
        root->right=bstFromPreorder(v,par);
        return root;
    }
};