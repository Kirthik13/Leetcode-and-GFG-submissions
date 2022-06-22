/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node *dum=new Node(-1);
        Node* curr=dum;
        
        Node* h1=head;
        while(h1)
        {
            Node* nxtnode=h1->next;
            
            Node* newnode=new Node(h1->val);
            h1->next=newnode;
            newnode->next=nxtnode;
            h1=nxtnode;
        }
        
        h1=head;
        while(h1)
        {
            if(h1->random)
            {
                h1->next->random=h1->random->next;
            }
            else{
                h1->next->random=NULL;
            }
            h1=h1->next->next;
        }
        h1=head;
        while(h1)
        {
            
            curr->next=h1->next;
            curr=curr->next;
            h1->next=h1->next->next;
            h1=h1->next;
        }
        return dum->next;
        
    }
};