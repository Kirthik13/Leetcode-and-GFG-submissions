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
    ListNode* findmid(ListNode* h1)
    {
        ListNode* s=h1;
        ListNode* f=h1->next;
        
        while((f and f->next))
        {
            s=s->next;
            f=f->next->next;
        }
        
        return s;
        
    }
    ListNode* sort(ListNode* h1,ListNode* h2)
    {
        ListNode* dum=new ListNode();
        ListNode* prev=dum;
        
        ListNode* l1=h1;
        ListNode* l2=h2;
        
        while(l1 and l2)
        {
            if(l1->val<=l2->val)
            {
                prev->next=l1;
                l1=l1->next;
                prev=prev->next;
            }
            else{
                prev->next=l2;
                l2=l2->next;
                prev=prev->next;
            }
        }
        
        while(l1)
        {
             prev->next=l1;
                l1=l1->next;
                prev=prev->next;
        }
        while(l2)
        {
            prev->next=l2;
                l2=l2->next;
                prev=prev->next;
        }
        
        prev->next=NULL;
        return dum->next;
    }
    ListNode* merge(ListNode* l1)
    {
        if(!l1->next) return l1;
        
        ListNode* mid=findmid(l1);
        
        ListNode* l2=mid->next;
        mid->next=NULL;
        
        ListNode* newnode=sort(merge(l1),merge(l2));
        return newnode;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
         if(!list1 or !list2)
         {
             return !list1?list2:list1;
         }
         
        ListNode* h1=list1;
        ListNode* h2=list2;

        while(h1->next)
        {
            h1=h1->next;
        }
        
        h1->next=h2;
        
        return merge(list1);
        
    }
};