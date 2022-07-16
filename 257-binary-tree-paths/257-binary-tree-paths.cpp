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
    void fn(TreeNode* root,string s, vector<string>&tot)
    {
        if(!root->left and !root->right)
        {
            string ch=to_string(root->val);
            s+=ch;
            tot.push_back(s);
            return ;
        }
        
        string ch=to_string(root->val);
            s+=ch;
        s+="->";
        if(root->left) fn(root->left,s,tot);
        if(root->right) fn(root->right,s,tot);

            
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string>tot;
        fn(root,"",tot);
        return tot;
    }
};