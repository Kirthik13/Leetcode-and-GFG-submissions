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
//     void fn1(TreeNode* root,multiset<int>&v)
//     {
//         if(!root) return;
        
//         fn1(root->left,v);
//         v.insert(root->val);
//         fn1(root->right,v);

            
//     }
//     void fn2(TreeNode* &root,multiset<int>&v)
//     {
//         if(!root) return;
        
//         fn2(root->left,v);
        
//         root->val=*v.begin();
//         v.erase(v.begin());
//         fn2(root->right,v);
//     }
    
    void fn(TreeNode* root,TreeNode* &first,TreeNode* &end,TreeNode* &prev)
    {
        if(!root) return;
        
        fn(root->left,first,end,prev);
        
        if(prev)
        {
            if(prev->val>root->val)
            {
                if(!first)
                {
                    first=prev;
                    
                }
                end=root;
            }
        }
        prev=root;
        
        fn(root->right,first,end,prev);
    }
    void recoverTree(TreeNode* root) {
        // multiset<int>v;
        // fn1(root,v);
        // fn2(root,v);
        TreeNode* first=NULL;TreeNode* end=NULL;TreeNode* prev=NULL;
        fn(root,first,end,prev);
        swap(first->val, end->val);
       

    }
};