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
    bool fn(TreeNode* root,int k,unordered_set<int>&st)
    {
        if(!root) return 0;
        int val=k-root->val;
        if(st.find(val)!=st.end()) return 1;
        st.insert(root->val);
       bool ln=fn(root->left,k,st);
        bool rn=fn(root->right,k,st);
        if(ln or rn) return 1;
        return 0;
        
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>st;
        return fn(root,k,st);
    }
};