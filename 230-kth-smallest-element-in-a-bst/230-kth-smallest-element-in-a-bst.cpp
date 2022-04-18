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
    int ans=INT_MIN;
    void fn(TreeNode* root, int &k)
    {
        
        if(!root) return;
        if(ans!=INT_MIN) return;
        fn(root->left,k);
        // cout<<"val : "<<root->val<<endl;
        k--;
        // cout<<"An : "<<ans<<endl;
        if(k==0 and ans==INT_MIN)
        {
            ans=root->val;
            return;
        }
        fn(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        fn(root,k);
        return ans;
            
    }
};