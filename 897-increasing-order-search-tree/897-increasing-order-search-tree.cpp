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
    vector<TreeNode*>v2;
    void fn(TreeNode* root)
    {
        if(!root) return;
        
        fn(root->left);

        TreeNode* g=new TreeNode(root->val);
        v2.push_back(g);
  
        fn(root->right);
            
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(!root ) return root;
        
        fn(root);
        // vector<TreeNode*>v2;
       
//         for(int i=0;i<v.size();i++)
//         {
     
//             TreeNode* g=new TreeNode(v[i]);
//             v2.push_back(g);
            
//         }
        for(int i=0;i<v2.size()-1;i++)
        {
            if(i==0) root=v2[i];
            v2[i]->right=v2[i+1];
        }
       
       return root;
    }
};