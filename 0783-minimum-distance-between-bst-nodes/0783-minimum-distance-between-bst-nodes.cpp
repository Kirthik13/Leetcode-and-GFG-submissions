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
    int ans=INT_MAX;
    vector<int>v;
    void fn(TreeNode* root) 
    {
        if(!root) return ;
                fn(root->left);

        int curr=root->val;
        v.push_back(curr);
        if(v.size()>=2)
        {
            // cout<<curr<<" "<<v[v.size()-2]<<endl;
            ans=min(ans,curr-v[v.size()-2]);
        }
        
       fn(root->right);
        
        
       
        
        
        
    }
    int minDiffInBST(TreeNode* root) {
        fn(root);
        return ans;
    }
};