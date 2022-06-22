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
    ListNode* fn(ListNode* &root)
    {
        if( !root or !root->next ) return root;
        
        ListNode* head=fn(root->next);
        ListNode* node=root->next;
        node->next=root;
        root->next=NULL;
      
        return head;
        
        
        
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* h=head;
        ListNode* ans=fn(h);
        
        return ans;
    }
};