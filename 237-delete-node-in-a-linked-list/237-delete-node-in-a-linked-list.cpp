/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
//         ListNode* h=node;
//         ListNode* prev;
//         while(h->next)
//         {
//             ListNode* nextnode=h->next;
//             h->val=nextnode->val;
//             prev=h;
//             h=h->next;
//         }
//         delete(prev->next);

//         prev->next=NULL;
        
        ListNode* h=node;
        
        ListNode* prev=h->next;
        swap(h->val,prev->val);
                h->next=h->next->next;

        // delete(prev);
        
    }
};