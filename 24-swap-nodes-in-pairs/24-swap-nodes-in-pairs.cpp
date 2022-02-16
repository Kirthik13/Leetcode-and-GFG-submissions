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
    ListNode* swapPairs(ListNode* head) {
         ListNode *dummy = new ListNode(0), *node;
    node = dummy;
    dummy->next = head;
      
    while (head && head->next) {
        ListNode *nxt = head->next;
        head->next = nxt->next;
        nxt->next = head;
        node->next = nxt;
        node = head;
        head = head->next;

    }
    return dummy->next;
//         ListNode* h=head;
//         ListNode* dum=new ListNode(0);
//                 ListNode* node;

//         dum->next=h;
//         while(!h and !h->next)
//         {
//             ListNode* nxt=h->next;
//             h->next=nxt->next;
//             nxt->next=h;
//             node->next=nxt;
//             node=h;
//             h=node->next;
//         }
//         return dum->next;
    }
};