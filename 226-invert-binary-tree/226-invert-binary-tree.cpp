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
    void  fn(TreeNode* r1)
    {
        if(!r1)
        {
            
            return;
        }
        
        fn(r1->left);
        fn(r1->right);
        swap(r1->left,r1->right);
        // r1->left=fn(r1->left,r2->right);
        // r=fn(r1->right,r2->left);
    }
    TreeNode* invertTree(TreeNode* r1) {
        // if(!root or (!root->left and !root->right)) return root;
        // fn(root);
        // return root;
         if(!r1)
        {
            
            return r1;
        }
        
        invertTree(r1->left);
        invertTree(r1->right);
        swap(r1->left,r1->right);
        return r1;
    }
};