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
    ListNode* midpoint(ListNode* head)
    {
        ListNode* s=head;
       ListNode*  f=head->next;
        // s=head;
        // f=head;
        
        while(f and f->next)
        {
            f=f->next->next;
            s=s->next;
        }
        return s;
        
        
    }
    ListNode* mergesort(ListNode* a,ListNode* b)
    {
        if(!b) return a;
        if(!a) return b;
        ListNode* temp;
        if(a->val<=b->val)
        {
            temp=a;
            temp->next=mergesort(a->next,b);
        }
        else{
            temp=b;
            temp->next=mergesort(a,b->next);
        }
       return temp;
        // mergesort()
    }
    ListNode* sortList(ListNode* head) {
        if(!head or (!head->next)) return head;
        ListNode* a=head;
        ListNode* mid=midpoint(head);
        ListNode* b=mid->next;
        mid->next=NULL;
        a=sortList(a);
        b=sortList(b);

        return mergesort(a,b);
    }
};