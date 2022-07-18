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
    void fn(TreeNode* root,int k,int &cnt,int &ans)
    {
        if(!root) return ;
        if(ans!=INT_MIN) return;
        fn(root->left,k,cnt,ans);
        if(cnt==k) ans=root->val;
        cnt++;
        fn(root->right,k,cnt,ans);
        
        
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=1,ans=INT_MIN;
         fn(root,k,cnt,ans);
        return ans;
    }
};