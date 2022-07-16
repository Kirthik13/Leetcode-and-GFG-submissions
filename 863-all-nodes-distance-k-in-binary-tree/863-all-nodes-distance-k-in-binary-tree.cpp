/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parentfn(TreeNode* root,TreeNode* par,unordered_map<TreeNode*,TreeNode*>&m)
    {
        if(!root) return;
        
        if(par!=NULL)
        {
            m[root]=par;
        }
        parentfn(root->left,root,m);
        parentfn(root->right,root,m);
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0) return {target->val};
     
        unordered_map<TreeNode*,TreeNode*>m;
        parentfn(root,NULL,m);
        
        queue<TreeNode*>q;
        q.push(target);
        
        vector<int>ans;
        unordered_set<TreeNode*>st;
        
        int k1=0;
        while(!q.empty() and k1<=k){
            
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto node=q.front();
                // cout<<"node : "<<node->val<<endl;
                q.pop();
                st.insert(node);
                if(k1==k) ans.push_back(node->val);
                if(m[node]!=NULL)
                {
                    if(st.find(m[node])==st.end()){
                    q.push(m[node]);
                    }
                }
                if(node->left)
                {
                    if(st.find(node->left)==st.end()){
                        q.push(node->left);

                    }
                }
                if(node->right)
                {
                     if(st.find(node->right)==st.end()){
                        q.push(node->right);

                    }
                }
            }
            k1++;
            
        }
        
        return ans;
    }
};