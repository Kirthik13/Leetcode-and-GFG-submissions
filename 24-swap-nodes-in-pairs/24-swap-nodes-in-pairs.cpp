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
    ListNode* fn(ListNode* h)
    {
        if(!h or !h->next) return h;
        ListNode* p=h;
        ListNode* ns=h->next;
                p->next=ns->next;
        
        ns->next=p;
        p->next=fn(p->next);
        return ns;
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode* h=head;
        return fn(h);
      
        
    }
};