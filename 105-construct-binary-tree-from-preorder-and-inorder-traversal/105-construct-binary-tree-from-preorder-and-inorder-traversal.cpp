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
    TreeNode* fn(vector<int>& pre, vector<int>& in,map<int,int>&m,int &idx,int st,int n)
    {
        if(st>n) return NULL;
        if(idx>=in.size()) return NULL;
        
        TreeNode* root=new TreeNode(pre[idx]);
        int mid=m[pre[idx]];
        idx++;
        root->left=fn(pre,in,m,idx,st,mid-1);
        root->right=fn(pre,in,m,idx,mid+1,n);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        map<int,int>m;
        for(auto i=0;i<in.size();i++) m[in[i]]=i;
        int idx{};
        int n=in.size();
        return fn(pre,in,m,idx,0,n);
    }
};