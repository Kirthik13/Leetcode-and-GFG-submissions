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
//     bool fn(TreeNode* p,TreeNode* q)
//     {
//         if(!p and !q) return 1;
//         if(!p) return 0;
//         if(!q) return 0;
        
//         if(p->val!=q->val) return 0;
//         bool lt=fn(p->left,q->right);
//         bool rt=fn(p->right,q->left);
        
//         if(!lt or !rt) return 0;
        
//         return 1;

//     }
    bool isSymmetric(TreeNode* root) {
        
        if(!root) return 1;
        
       
        
        stack<TreeNode*>st1,st2;
        
        st1.push(root);
        st2.push(root);
        
        while(!st1.empty() and !st2.empty())
        {
             TreeNode* p=st1.top();
             TreeNode* q=st2.top();
             
             st1.pop();
             st2.pop();
            
             if(p->val!=q->val) return 0;
            
             if(p->right or q->left)
             {
                 if(!q->left) return 0;
                 if(!p->right) return 0;
                 
                 st1.push(p->right);
                 st2.push(q->left);
                 
             }
              
             if(q->right or p->left)
             {
                 if(!p->left) return 0;
                 if(!q->right) return 0;
                 
                 st2.push(q->right);
                 st1.push(p->left);
                 
             }
            
                
            
                
        }
        
        if(st1.empty() and st2.empty()) return 1;
        return 0;
        
    }
};