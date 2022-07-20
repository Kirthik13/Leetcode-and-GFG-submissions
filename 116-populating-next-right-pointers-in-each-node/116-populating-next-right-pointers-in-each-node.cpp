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
    Node* connect(Node* root) {
        if(!root) return NULL;
        
        Node* dum=new Node();
        Node* head=root;
        while(head)
        {
            Node* curr=head;
            Node* prev=dum;
            while(curr)
            {
                if(curr->left)
                {
                    prev->next=curr->left;
                    prev=prev->next;
                }
                if(curr->right)
                {
                    prev->next=curr->right;
                    prev=prev->next;

                }
                curr=curr->next;
            }
            head=dum->next;
            dum->next=NULL;
        }
        return root;
    }
};