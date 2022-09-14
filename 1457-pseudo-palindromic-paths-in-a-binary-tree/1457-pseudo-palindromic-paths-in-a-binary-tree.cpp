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
    unordered_map<int,int>m;
    void fn(TreeNode* root,int &cnt) 
    {
        if(!root) return ;
        if(!root->left and !root->right)
        {
            m[root->val]++;
            // cout<<root->val<<endl;
            
            int ev{},odd{},totsiz{};
            for(auto &i:m)
            {
                totsiz+=i.second;
                // cout<<i.first<<" ";
                if(i.second%2!=0)
                {
                    odd++;
                }
                else{
                    ev++;
                }
            }
            // cout<<endl;
            if(totsiz%2==0)
            {
            // cout<<totsiz<<" "<<ev<<" "<<odd<<endl;
                
                if(ev==m.size()) cnt++;
            }
            else{
                if(ev==m.size()-1 and odd==1 )cnt++;
            }
              m[root->val]--;
        if(m[root->val]==0) m.erase(root->val);
            return ;
        }
        
        
        m[root->val]++;
        // cout<<root->val<<" ";
        fn(root->left,cnt);
        fn(root->right,cnt);
        // cout<<endl;
        m[root->val]--;
        if(m[root->val]==0) m.erase(root->val);

            
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        
        int cnt{};
        fn(root,cnt);
        return cnt;
    }
};