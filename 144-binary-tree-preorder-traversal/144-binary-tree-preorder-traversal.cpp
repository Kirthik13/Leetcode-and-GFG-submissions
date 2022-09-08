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
    vector<int> preorderTraversal(TreeNode* root) {
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
                    ans.push_back(cur->val);
                    
                    cur=cur->left;
                }
                else{
                    prev->right=NULL;
                    cur=cur->right;
                }
                
                
            }
        }
        return ans; 
            
    }
};