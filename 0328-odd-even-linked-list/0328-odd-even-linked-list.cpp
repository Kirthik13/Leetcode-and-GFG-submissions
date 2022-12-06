/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
      
        if(!head or !head->next) return head;
        
        ListNode* dum1=new ListNode();
        ListNode* p1=dum1;

        ListNode* dum2=new ListNode();
        ListNode* p2=dum2;        
        ListNode* h=head;
        
        int f=0;
        
        while(h)
        {
            if(!f)
            {
                p1->next=h;
                p1=p1->next;
            }
            else
            {
                p2->next=h;
                p2=p2->next;                
            }
            
            f=1-f;
        
            h=h->next;
        }
        
        p1->next=dum2->next;
        p2->next=NULL;
        
        return dum1->next;
        
        
    }
};