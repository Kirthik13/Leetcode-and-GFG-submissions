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
    void fn(TreeNode* root, int &l, int &h,int &ans) 
    {
        if(!root) return ;
        
//          if(!(root->val>=l and root->val<=h))
//         {
//              if(root->val<l)
//              {
//                 fn(root->right,l,h,ans);
//              }
//              else{
//                  fn(root->left,l,h,ans);
//              }
//              return;
//         }
        
//         else if(root->val>=l and root->val<=h)
//         {
//             ans+=root->val;
//         }
        
//         fn(root->left,l,h,ans);
//         fn(root->right,l,h,ans);
        fn(root->left,l,h,ans);
        if(root->val>=l and root->val<=h)
        {
            ans+=root->val;
        }
        fn(root->right,l,h,ans);
        
        
    }
    int rangeSumBST(TreeNode* root, int l, int h) {
        int ans{};
        fn(root,l,h,ans);
        return ans;
    }
};