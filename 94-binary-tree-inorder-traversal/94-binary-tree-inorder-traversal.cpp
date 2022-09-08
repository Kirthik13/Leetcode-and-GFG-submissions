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
    vector<int> inorderTraversal(TreeNode* root) {
        
        TreeNode* cur=root;
        vector<int>ans;
        while(cur)
        {
            if(!cur->left)
            {
                ans.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode* prev=cur->left;
                
                while(prev->right and prev->right!=cur)
                {
                    prev=prev->right;
                }
                
                if(!prev->right)
                {
                    prev->right=cur;
                    cur=cur->left;
                }
                else{
                    ans.push_back(cur->val);
                    prev->right=NULL;
                    cur=cur->right;
                }
                
            }
        }
        
        return ans;
            
    }
};