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
    vector<int>sums;
    void dfs(TreeNode* root,int lvl) 
    {
        if(!root) return;
        sums.resize(max((int)sums.size(),lvl));
        sums[lvl-1]+=root->val;
        dfs(root->left,lvl+1);
        dfs(root->right,lvl+1);
        
        
    
    }
    int maxLevelSum(TreeNode* root) {
        
//         queue<TreeNode*>q;
        
//         q.push(root);
//         int lev=INT_MAX,ans=INT_MIN;
//         int levcnt=1;
//         while(!q.empty())
//         {
//             int n=q.size();
//             int sum{};
//             for(int i=0;i<n;i++)
//             {
//                 auto node=q.front();
//                 sum+=node->val;
//                 q.pop();
//                 if(node->left) q.push(node->left);
//                 if(node->right) q.push(node->right);
                
//             }
//             if(ans<sum)
//             {
//                 lev=levcnt;
//                 ans=sum;
//             }
//             levcnt++;
//         }
//         return lev;
            dfs(root,1);
        return distance(begin(sums),max_element(begin(sums),end(sums)))+1;
    }
};