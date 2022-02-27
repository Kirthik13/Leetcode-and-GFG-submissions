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
#define ull unsigned long long
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root->left and !root->right)
        {
            return 1;
        }
//         queue<pair<TreeNode*,unsigned long long int>>q;
//         q.push({root,0});
//         unsigned long long int ans=0;
        
//         while(!q.empty())
//         {
//             unsigned int n=q.size();
//             unsigned long long int end{};
//             unsigned long long int st=q.front().second;
//             for(int i=0;i<n;i++)
//             {
//                 TreeNode* t=q.front().first;
//                 unsigned long long int curr=q.front().second;
//                 q.pop();
//                 if(i==n-1)
//                 {
//                     end=curr;
//                 }
//                 if(t->left)
//                 {
//                     q.push({t->left,2*curr+1});
//                 }
//                if(t->right)
//                 {
//                     q.push({t->right,2*curr+2});
//                 }   
//             }
//             if(ans<end-st+1)
//             {
//                 ans=end-st+1;
//             }
                
        // }
        ull ans{};
        queue<pair<TreeNode*,ull>>q;
        q.push({root,0});
        while(!q.empty())
        {
            ull n=q.size();
            ull st=q.front().second;
            
            ull end{};
            for(int i=0;i<n;i++)
            {
                ull curr=q.front().second;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==n-1)
                    
                {
                    end=curr;
                }
                if(node->left)
                {
                    q.push({node->left,2*curr+1});
                    
                }
                if(node->right)
                {
                    q.push({node->right,2*curr+2});
                }
            }
            if(ans<end-st+1) ans=end-st+1;
        }
        return ans;
    }
};