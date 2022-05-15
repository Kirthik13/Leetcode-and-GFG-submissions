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
    int fn(TreeNode* root)
    {
        queue<TreeNode*>q;
        q.push(root);
        int cnt{};
        while(!q.empty())
        {
            int n=q.size();
            cnt=0;
            for(int i=0;i<n;i++)
            {
                TreeNode* t=q.front();
                cnt+=t->val;
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);

            }
        }
        return cnt;
    }
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        if(!root->left and !root->right) return root->val;
        
        return fn(root);
        
    }
};