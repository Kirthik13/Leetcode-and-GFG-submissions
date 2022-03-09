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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* h=head;
        ListNode* p=head;
        ListNode* ans=head;
        unordered_map<int,int>m;
        while(p)
        {
            m[p->val]++;
            p=p->next;
        }
        ListNode* dum=new ListNode();
        ListNode* t=dum;
        while(h)
        {
            if(m[h->val]==1)
            {
              t->next=h;
                t=t->next;
            }
            h=h->next;
        }
        t->next=NULL;
        return dum->next;
        
        
    }
};