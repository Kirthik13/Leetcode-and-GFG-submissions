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
    int fn(TreeNode* root,int mn,int mx) 
    {
        if(!root) return mx-mn;
        
        mx=max(root->val,mx);
        mn=min(root->val,mn);
        
        return max(fn(root->left,mn,mx),fn(root->right,mn,mx));
        // if (root == null) return mx - mn;
        // mx = Math.max(mx, root.val);
        // mn = Math.min(mn, root.val);
        // return Math.max(dfs(root.left, mn, mx), dfs(root.right, mn, mx));
        
        
        
        
        
        
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans{};
        return fn(root,root->val,root->val);
        
    }
};