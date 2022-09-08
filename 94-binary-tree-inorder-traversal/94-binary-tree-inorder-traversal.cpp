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
        vector<TreeNode*>v;
        vector<int>ans;
        
        TreeNode* node=root;
        
        while(1)
        {
            if(node)
            {
                v.push_back(node);
                node=node->left;
            }
            else{
                if(v.empty()) break;
                node=v.back();
                ans.push_back(node->val);
                v.pop_back();
                node=node->right;
            }
        }
        
        return ans;
            
            
    }
};