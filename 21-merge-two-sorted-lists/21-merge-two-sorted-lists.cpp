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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
       // ,h2;
         ListNode* h1=list1;
         ListNode* h2=list2;
        if(!h1 or  !h2)
        {
            if(h1) return h1;
            return h2;
        }
        ListNode* dum=new ListNode(0);
        ListNode* p=dum;
        while(h1 and h2)
        {
            if(h1->val<h2->val)
            {
                p->next=h1;
                p=p->next;
                h1=h1->next;
            }
            else{
                 p->next=h2;
                p=p->next;
                h2=h2->next;
            }
        }
        if(h1)
        {
            p->next=h1;
            
        }
        if(h2)
        {
            p->next=h2;
        }
        return dum->next;
    }
};