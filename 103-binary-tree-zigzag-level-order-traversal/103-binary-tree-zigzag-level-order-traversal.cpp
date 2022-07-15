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
        if(!root) return {};
        vector<vector<int>>ans;
        
        queue<TreeNode*>q;
        q.push(root);
        int flag=0;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>curr;
            // cout<<"fl : "<<flag<<endl;
            for(int i=0;i<n;i++)
            {
                auto node=q.front();
                if(flag==0)
                {
                    curr.push_back(node->val);
                }
                else{
                    curr.insert(curr.begin(),node->val);
                }
                // cout<<node->val<<" ";
                q.pop();
                
                        if(node->left) q.push(node->left);
                        if(node->right) q.push(node->right);


                
            }
            flag=1-flag;
            ans.push_back(curr);
        }
        return ans;
    }
};