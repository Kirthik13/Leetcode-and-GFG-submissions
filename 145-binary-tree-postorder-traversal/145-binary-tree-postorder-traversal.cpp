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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* cur=root;
        vector<int>ans;
        while(cur)
        {
            if(!cur->right)
            {
                ans.push_back(cur->val);
                cur=cur->left; //r
            }
            else{
                TreeNode* prev=cur->right;
                
                while(prev->left and prev->left!=cur)//r
                {
                    prev=prev->left;//r
                }
                
                if(!prev->left)//r
                {
                    prev->left=cur;//r
                    ans.push_back(cur->val);
                    
                    cur=cur->right;
                }
                else{
                    prev->left=NULL;//r
                    cur=cur->left;//r
                }
                
                
            }
        }
        reverse(begin(ans),end(ans));
        return ans; 
    }
};