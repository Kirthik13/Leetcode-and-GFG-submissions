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
    TreeNode* fn(vector<int>& v,int st,int en)
    {
         if(st>en) return NULL;
        int mid=(st+en)/2;
        TreeNode* root=new TreeNode(v[mid]);
        
        root->left=fn(v,st,mid-1);
        root->right=fn(v,mid+1,en);
        
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& v) {
        int n=v.size();
        
        return fn(v,0,n-1);
    }
};