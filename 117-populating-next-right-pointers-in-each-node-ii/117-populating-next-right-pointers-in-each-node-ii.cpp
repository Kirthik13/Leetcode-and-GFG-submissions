/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void fn(Node* &root)
    {
 
        queue<Node*>q;
        if(!root) return;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<Node*>st;
            
            for(int i=0;i<n;i++)
            {
                Node* t=q.front();
                st.push_back(t);
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            
            }
            for(int i=0;i<st.size()-1;i++)
            {
                Node* t1=st[i];
                Node* t2=st[i+1];
                
                t1->next=t2;
            }
        }
            

        
    }
    Node* connect(Node* root) {
        vector<Node*>v;
        if(!root or (!root->left and !root->right)) return root;
        fn(root);

        return root;
        
    }
};