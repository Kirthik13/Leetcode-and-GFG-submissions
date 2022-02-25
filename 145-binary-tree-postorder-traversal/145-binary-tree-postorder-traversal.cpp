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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int>v;
        // stack<TreeNode*>st1,st2;
        // st1.push(root);
        // while(!st1.empty())
        // {
        //     TreeNode* node=st1.top();
        //     st1.pop();
        //     st2.push(node);
        //     if(node->left)
        //     {
        //         st1.push(node->left);
        //     }
        //     if(node->right)
        //     {
        //         st1.push(node->right);
        //     }
        // }
        // while(!st2.empty())
        // {
        //     v.push_back(st2.top()->val);
        //     st2.pop();
        // }
        stack<TreeNode*>st;
        TreeNode* cur=root;
        while(cur or !st.empty())
        {
            if(cur)
            {
                st.push(cur);
                cur=cur->left;
            }
            else{
                TreeNode* temp=st.top()->right;
                if(!temp)
                {
                    temp=st.top();
                    v.push_back(temp->val);
                    st.pop();
                    while(!st.empty() and temp==st.top()->right)
                    {
                        temp=st.top();
                        st.pop();
                        v.push_back(temp->val);
                    }
                        
                }
                else{
                    cur=temp;
                }
            }
        }
        return v;
    }
};