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
    int fn(TreeNode* node,int sum)
    {
        if(!node)
        {
            return 0;
        }
        
        sum=(sum<<1)|node->val;
        if(!node->left and !node->right)
        {
            return sum;
        }
        return fn(node->left,sum)+fn(node->right,sum);
    }
    int sumRootToLeaf(TreeNode* root) {
        // int sum=0;
        return fn(root,0);
        
    }
};