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
    int fn(TreeNode* root,int &ans)
    {
        if(!root) return 0;
        
        int hl=fn(root->left,ans);
        int hr=fn(root->right,ans);
        
        ans=max(ans,hl+hr);
        
        return 1+max(hr,hl);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans=INT_MIN;
        int g=fn(root,ans);
        
        return ans;
    }
};