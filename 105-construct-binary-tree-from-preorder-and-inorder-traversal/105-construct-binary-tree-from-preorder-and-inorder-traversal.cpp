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
    unordered_map<int,int>m;
    TreeNode* fn(vector<int>& pre, vector<int>& in,int st,int en,int &idx) 
    {
        if(st>en) return NULL;
        
        TreeNode* root=new TreeNode(pre[idx]);
        
        int mid=m[pre[idx]];
        
        idx++;
        
        root->left=fn(pre,in,st,mid-1,idx);
        root->right=fn(pre,in,mid+1,en,idx);

        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        for(auto i=0;i<in.size();i++)
        {
            m[in[i]]=i;
        }
        int n=pre.size()-1;
        int idx{};
        return fn(pre,in,0,n,idx);
    }
};