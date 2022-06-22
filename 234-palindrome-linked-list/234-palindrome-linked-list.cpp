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
    ListNode* tem;
    bool fn(ListNode* h)
    {
        if(!h->next)
        {
            if(tem->val==h->val)
            {
                tem=tem->next;
                return 1;
            }
            return 0;
        }
        if(!fn(h->next)) return 0;
        if(tem->val==h->val)
        {
            tem=tem->next;
            return 1;
        }
        return 0;
    }
    bool isPalindrome(ListNode* head) {
        tem=head;
        return fn(head);
    }
};