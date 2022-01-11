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
    int ans{};
    vector<string>v;
    void fn(TreeNode* node,string &s)
    {
        if(node==NULL)
        {
            
            // v.push_back(s);
            return;
        }
        char c=(node->val)+48;
        s.push_back(c);
        fn(node->left,s);
        fn(node->right,s);
        if(!node->right and !node->left){
         v.push_back(s);
        }
        s.pop_back();
        

        
    }
    int sumRootToLeaf(TreeNode* root) {
        string s="";
        fn(root,s);
        for(int i=0;i<v.size();i++)
        {
            string k=v[i];
            // cout<<" k : "<<k<<endl; 
            int p=0;
            int j=k.size()-1;
            int cnt{};
            while(j>=0)
            {
                if(k[j]=='1')
                {
                    cnt=cnt+pow(2,p);
                }
                p++;
                j--;
            }
            ans+=cnt;
            // cout<<" cnt : "<<cnt<<endl;
            // cout<<"ans : "<<ans<<endl;
            
        }
        // for(auto i:v)
        // {
            // cout<<i<<" ";
        // }
        return ans;
    }
};