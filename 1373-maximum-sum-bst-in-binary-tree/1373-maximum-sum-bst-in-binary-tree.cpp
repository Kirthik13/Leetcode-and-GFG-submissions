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
//     int fn(TreeNode* root,int &mn,int &mx)
//     {
//         if(!root) return 0;
        
//         int lmn=INT_MAX,lmx=INT_MIN,rmn=INT_MAX,rmx=INT_MIN;
        
//         int l=fn(root->left,lmn,lmx);
//         int r=fn(root->right,rmn,rmx);
        
//         int val=l+r+root->val;
//         if(lmx<root->val and rmn>root->val)
//         {
            
//             // if(root->val==3)
//             // {
//             //     cout<<lmx<<" "<<rmn<<endl;
//             //     cout<<"ASd";
//             // }
//             ans=max(ans,val);
//            mx=max(root->val,rmx);
//             mn=min(root->val,lmn);
//         }
//         else{
//             mn=INT_MIN;
//             mx=INT_MAX;
//         }
//         return val;
//     }
    // int maxSumBST(TreeNode* root) {
    //     int mx=INT_MIN,mn=INT_MAX;
    //     fn(root,mn,mx);
    //     return ans;
    // }
        int fn(TreeNode* root,int &mn,int &mx)
        {
            if(!root) return 0;
            int lmn,rmn,lmx,rmx;
            lmn=rmn=INT_MAX;
            lmx=rmx=INT_MIN;
            int l=fn(root->left,lmn,lmx);
            int r=fn(root->right,rmn,rmx);
            int val=l+r+root->val;
            if(lmx<root->val and rmn>root->val)
            {
                ans=max(ans,val);
                mx=max(root->val,rmx);
                mn=min(root->val,lmn);
            }
            else{
                mn=INT_MIN;
                mx=INT_MAX;
            }
          return val;
        }
      int maxSumBST(TreeNode* root) {
        int mx=INT_MIN,mn=INT_MAX;
        fn(root,mn,mx);
        return ans;
    }
};