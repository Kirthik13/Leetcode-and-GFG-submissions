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
    void fn(TreeNode* node,stack<TreeNode*>&v)
    {
        if(!node)
        {
            return;
        }
   

        v.push(node);
        fn(node->left,v);
        
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        if(!root1 and !root2)
        {
            return {};
        }

        
        vector<int>ans;
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
     
        fn(root1,s1);
        fn(root2,s2);
        while(s1.size()>0 and s2.size()>0)
        {
            TreeNode* r1=s1.top();
            TreeNode* r2=s2.top();
         
            if(r1->val<r2->val)
            {
                ans.emplace_back(r1->val);
                s1.pop();
                fn(r1->right,s1);
            }
            else{
                ans.emplace_back(r2->val);
                s2.pop();
                fn(r2->right,s2);
            }
            

        }
        stack<TreeNode*>s=s1.empty()?s2:s1;
      
        while(s.size()>0)
        {
            TreeNode* r1=s.top();
            s.pop();
            ans.emplace_back(r1->val);
            fn(r1->right,s);
        }
        return ans;
        
    }
};