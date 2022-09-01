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
    void fn(TreeNode* root,int curval,int &cnt) 
    {
        if(!root) return ;
        
        if(curval<=root->val) cnt++;
        curval=max(curval,root->val);
        fn(root->left,curval,cnt);
        fn(root->right,curval,cnt);
        
            
    }
    int goodNodes(TreeNode* root) {
        int curval=root->val,cnt=0;
        fn(root,curval,cnt);
        return cnt;
    }
};