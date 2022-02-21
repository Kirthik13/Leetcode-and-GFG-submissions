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
    int fn(TreeNode* root,bool &ch)
    {
        if(!ch) return 0;
        if(!root) return 0;
        
        int l=fn(root->left,ch);
        int r=fn(root->right,ch);
        // cout<<" l : "<<l<<" r : "<<r<<endl;
        if(abs(l-r)>1)
        {
            ch=0;
            return 0;
        }
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return 1;
        bool ch=1;
        int g=fn(root,ch);
        return ch;
            
    }
};