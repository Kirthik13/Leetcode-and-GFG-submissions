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
        if(!head ) return head;
        Node* h=head;
        Node* dum=new Node(0);
        Node* p=dum;
        while(h)
        {
            Node* h2=new Node(h->val);
            h2->next=h->next;
            h->next=h2;
            
            h=h2->next;
        }
        h=head;
        while(h)
        {
            if(h->random){
            h->next->random=h->random->next;
            }
            else{
                h->next->random=NULL;
            }
            h=h->next->next;
        
        }
        h=head;
        while(h)
        {
            p->next=h->next;
            p=p->next;
            h->next=h->next->next;
            h=h->next;
        }
        return dum->next;
        
        
    }
};