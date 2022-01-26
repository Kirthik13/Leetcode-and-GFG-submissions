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
    void fn(TreeNode* node,multiset<int>&v)
    {
        if(!node)
        {
            return;
        }
                fn(node->left,v);

        v.insert(node->val);
        fn(node->right,v);
        
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        if(!root1 and !root2)
        {
            return {};
        }
        multiset<int>v;
        fn(root1,v);
        fn(root2,v);
        
        vector<int>ans(v.begin(),v.end());
        return ans;
        
    }
};