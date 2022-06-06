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
    ListNode *getIntersectionNode(ListNode *headA1, ListNode *headB1) {
        ListNode *headA=headA1 ;
        ListNode *headB=headB1;
        while(headA and headB)
        {
            if(headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
   
            if(headA==NULL and headB) headA=headB1;
            if(headB==NULL and headA) headB=headA1;

        }
        return NULL;
    }
};