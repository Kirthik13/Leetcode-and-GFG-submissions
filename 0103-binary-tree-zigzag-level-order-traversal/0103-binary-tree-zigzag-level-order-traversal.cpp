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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
          vector<vector<int>>totans;
        if(!root) return totans;
        queue<TreeNode*>q;
        q.push(root);
        int fl=0;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>curr;
            for(int i=0;i<n;i++)
            {
                auto node=q.front();
                curr.push_back(node->val);
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
            }
            if(fl)
            {
                reverse(begin(curr),end(curr));
                
            }
            totans.push_back(curr);
            fl=1-fl;
        }
        return totans;
    }
};