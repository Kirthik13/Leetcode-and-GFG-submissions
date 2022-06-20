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
0-> no camera
1->covered
2->has camera
 */

class Solution {
public:
    int res{};
    int fn(TreeNode* root)
    {
        if(!root) return 1;
        int l=fn(root->left);
        int r=fn(root->right);
        
      
        if(l==0 or r==0)
        {
            res++;
            return 2;
        }
        
        
            if(l==1 and r==1)
            {
                
                return 0;
            }
        
         if(l==2 or r==2)
         {
             return 1;
         }
       
     
       
        return 0;
        
    }
    int minCameraCover(TreeNode* root) {
        if(!root->left and !root->right) return 1;
        int g=fn(root);
       if(g==0) res++;
        return res;
    }
};