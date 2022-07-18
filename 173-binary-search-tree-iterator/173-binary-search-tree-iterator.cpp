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
class BSTIterator {
public:
    map<int,int>m;
    void fn(TreeNode* root)
    {
        if(!root) return;
        
        fn(root->left);
        m[root->val]++;
        fn(root->right);
        
    }
    BSTIterator(TreeNode* root) {
        fn(root);
    }
    
    int next() {
        int val=m.begin()->first;
        m.erase(m.begin());
        return val;
    }
    
    bool hasNext() {
        if(m.size()>0) return 1;
        return 0;
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */