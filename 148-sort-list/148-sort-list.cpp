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
    ListNode* sortList(ListNode* head) {
        if(!head or (!head->next)) return head;
        multiset<int>ms;
        ListNode* dum=new ListNode(0);
        ListNode* p=dum;
        ListNode* h=head;
        while(h)
        {
            ms.insert(h->val);
            h=h->next;
        }
        for(auto &i:ms)
        {
            ListNode* node=new ListNode(i);
            p->next=node;
            p=p->next;
        }
        p->next=NULL;
        return dum->next;
    }
};