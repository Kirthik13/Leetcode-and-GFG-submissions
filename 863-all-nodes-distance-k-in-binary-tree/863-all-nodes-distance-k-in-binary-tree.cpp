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
    unordered_map<TreeNode*,TreeNode*>m;
    void dfs(TreeNode* root)
    {
        if(!root) return;
        if(root->left){
        m[root->left]=root;
            
            }
        if(root->right)
        {
            m[root->right]=root;
        }
        dfs(root->left);
        dfs(root->right);
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root);
        m[root]=NULL;
        vector<int>tot;
        queue<TreeNode*>q;
        q.push(target);
        int c=0;
        unordered_set<TreeNode*>st;
        st.insert(target);
        while(!q.empty() and c<k)
        {
            
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* t=q.front();
                q.pop();
                if(t->left and st.find(t->left)==st.end())
                {
                    q.push(t->left);
                    st.insert(t->left);
                }
                if(t->right and st.find(t->right)==st.end())
                {
                    q.push(t->right);
                            st.insert(t->right);

                }
                if(st.find(m[t])==st.end() and m[t]!=NULL)
                {
                    q.push(m[t]);
                    st.insert(m[t]);

                }
                
            }
            c++;
            
        }
        while(!q.empty())
        {
            tot.emplace_back(q.front()->val);
            q.pop();
        }
        return tot;
    }
};