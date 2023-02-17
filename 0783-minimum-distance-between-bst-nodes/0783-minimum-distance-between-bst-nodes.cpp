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
    int ans=INT_MAX;
    void fn(TreeNode* root,int &prev) 
    {
        if(!root) return ;
                fn(root->left,prev);

        int curr=root->val;
        // v.push_back(curr);
        
        if(prev!=INT_MAX)
        {
            ans=min(ans,curr-prev);
        }
        prev=curr;
       fn(root->right,prev);
        
        
       
        
        
        
    }
    int minDiffInBST(TreeNode* root) {
        int prev=INT_MAX;
        fn(root,prev);
        return ans;
    }
};