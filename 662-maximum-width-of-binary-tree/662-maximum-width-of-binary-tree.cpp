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
#define ull unsigned long long
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,ull>>q;
        q.push({root,0});
        ull ans{};
        while(!q.empty())
        {
            int n=q.size();
            ull st=0,end=0;
            for(int i=0;i<n;i++)
            {
                auto it=q.front();
                q.pop();
                
                auto node=it.first;
                auto idx=it.second;
                
                if(i==0) st=idx;
                if(i==n-1) end=idx;
                
                if(node->left)
                {
                    q.push({node->left,2*idx+1});
                }
                if(node->right)
                {
                    q.push({node->right,2*idx+2});
                }
                
            }
            ans=max(ans,end-st+1);
        }
        return ans;
    }
};