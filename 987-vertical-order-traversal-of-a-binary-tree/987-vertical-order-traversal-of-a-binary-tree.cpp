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
        if(!root) return {};
        vector<vector<int>>totans;
        map<int,map<int,multiset<int>>>m;
        queue<pair<int,pair<int,TreeNode*>>>q;
        q.push({0,{0,root}});
        
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            auto node=it.second.second;
            auto pt=it.first;
            auto lvl=it.second.first;
            
            m[pt][lvl].insert(node->val);
            
            if(node->left) q.push({pt-1,{lvl+1,node->left}});
            if(node->right) q.push({pt+1,{lvl+1,node->right}});
            
        }
        
        for(auto &i:m)
        {
            vector<int>curr;
            for(auto &j:i.second)
            {
                curr.insert(curr.end(),j.second.begin(),j.second.end());
            }
            totans.push_back(curr);
        }
        return totans;
    }
};