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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;
        if(root->val==val) return root;
        // TreeNode* l,r;
        if(root->val>val){
          TreeNode*  l=searchBST(root->left,val);
            if(l) return l;
        }
        else{
           TreeNode*  r=searchBST(root->right,val);
            if(r) return r;
        }
        // if(l) return l;
        // if(r) return r;
        return NULL;
            
    }
};