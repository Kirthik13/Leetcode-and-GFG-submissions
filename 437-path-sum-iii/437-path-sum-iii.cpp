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
        unordered_map<long long int,int>m;
    
    void fn(TreeNode* root, int k,int &cnt,long long int sum) 
    {
//         if(!root)
//         {
            
//             return ;
//         }
        
//         sum+=root->val;
//         if(m.find(sum-k)!=m.end()) cnt+=m[sum-k];
//                 m[sum]++;

//         fn(root->left,k,cnt,sum);
//         fn(root->right,k,cnt,sum);
        
//         m[sum]--;
        if (!root) return;
        
        sum += root->val;
        if (m.find(sum - k) != m.end()) cnt+= m[sum - k];
        m[sum]++;
        
        fn(root->left, k,  cnt,sum);
        fn(root->right, k,  cnt,sum);
        
        m[sum]--;
       
    }
    int pathSum(TreeNode* root, int k) {
        
        m[0]++;
        int cnt{};
        fn(root,k,cnt,0LL);
        return cnt;
    }
};