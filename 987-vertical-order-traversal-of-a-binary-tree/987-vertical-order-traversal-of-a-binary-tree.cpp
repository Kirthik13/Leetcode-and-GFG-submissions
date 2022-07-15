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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>>m;
        queue<pair<TreeNode*,int>>q;
        vector<vector<int>>totans;
        
        q.push({root,0});
        
        while(!q.empty())
        {
            int n=q.size();
            
            multiset<pair<int,int>>curr;
            for(int i=0;i<n;i++)
            {
                auto it=q.front();
                q.pop();
                auto node=it.first;
                auto pt=it.second;
                curr.insert({node->val,pt});
                
                if(node->left) q.push({node->left,pt-1});
                if(node->right) q.push({node->right,pt+1});
               
            }
          
            for(auto &i:curr)
            {
                m[i.second].push_back(i.first);
            }
                
        }
        
        for(auto &i:m)
        {
            totans.push_back(i.second);
        }
        return totans;
        
    }
};