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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        // int cnt=pow(2,depth-1);
        
        if(d==1)
        {
            return new TreeNode(v,root,NULL);
        }
        
        queue<TreeNode*>q;
        q.push(root);
        while(--d)
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front();
                
                if(d>1)
                {
                
                    if(curr->left)
                    {
                        q.push(curr->left);
                    }
                    if(curr->right)
                    {
                        q.push(curr->right);
                    }
                
                }
                else{
                    curr->left=new TreeNode(v,curr->left,NULL);
                    curr->right=new TreeNode(v,NULL,curr->right);
                    
                }
                
                q.pop();
                
                
            }
        }
        return root;
    }
};