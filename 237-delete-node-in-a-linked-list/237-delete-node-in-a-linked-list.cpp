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
        ListNode* h=node;
        ListNode* prev;
        while(h->next)
        {
            ListNode* nextnode=h->next;
            h->val=nextnode->val;
            prev=h;
            h=h->next;
        }
        prev->next=NULL;
        // delete(h);
        
    }
};