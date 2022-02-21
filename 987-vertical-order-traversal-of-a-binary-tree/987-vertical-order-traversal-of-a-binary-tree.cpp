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
        if( (!root->left and !root->right))
        {
            return {{root->val}};
        }
        vector<vector<int>>tot;
        queue<pair<TreeNode*,int>>q;
        map<int,vector<int>>m;
        q.push({root,0});

        while(!q.empty())
        {
            int n=q.size();
                   multiset<pair<int,int>>mt;

            for(int i=0;i<n;i++)
            {
                TreeNode* t=q.front().first;
                int  pos=q.front().second;
                mt.insert({pos,t->val});
                q.pop();
                if(t->left)
                {
                    q.push({t->left,pos-1});
                }
                if(t->right)
                {
                    q.push({t->right,pos+1});
                } 
            }
            for(auto &i:mt)
            {
                m[i.first].push_back(i.second);
            }
            
        }
        for(auto &i:m)
        {
          
            tot.emplace_back(i.second);
        }
        return tot;
    }
};