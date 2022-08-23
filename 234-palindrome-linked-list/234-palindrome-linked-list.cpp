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
    bool fn(ListNode* head,ListNode* &tem)
    {
        if(!head) return 1;
        
        if(!fn(head->next,tem)) return 0;
        
        if(tem->val==head->val)
        {
            tem=tem->next;
            return 1;
        }
        return 0;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* tem=head;
        return fn(head,tem);
    }
};