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
    vector<vector<int>>totans;
    void fn(TreeNode* root, int k, vector<int>&v,int sum)
    {
        if(!root) return;
        if(!root->left  and !root->right)
        {
                            v.push_back(root->val);

            if(sum+root->val==k )
            {
            
                totans.push_back(v);
            }
                            v.pop_back();

            return;
        }
        
        v.push_back(root->val);
        fn(root->left,k,v,sum+root->val);
        fn(root->right,k,v,sum+root->val);
        if(v.size()>0 ) v.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int k) {
        vector<int>v;
        fn(root,k,v,0);
        // vector<vector<int>>totan(begin(totans),end(totans));
        return totans;
    }
};