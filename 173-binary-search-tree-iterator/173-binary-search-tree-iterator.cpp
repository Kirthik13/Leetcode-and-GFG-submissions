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
    TreeNode* root=NULL;
    deque<int>dq;

    void fn(TreeNode* root)
    {
        if(!root) return;
        
        fn(root->left);
        dq.push_back(root->val);
        fn(root->right);
    }
    BSTIterator(TreeNode* root) {
        this->root=root;
        fn(root);
    }
    
    int next() {
     
          int ans=dq.front();
          dq.pop_front();
          return ans;
      
        
    }
    
    bool hasNext() {
        if(!dq.empty()) return 1;
        return 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */