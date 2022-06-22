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
    ListNode* reverse(ListNode* root)
    {
        if(!root->next)
        {
            return root;
        }
        ListNode* head=reverse(root->next);
        root->next->next=root;
        root->next=NULL;
        return head;
    }
    ListNode* fn(ListNode* head,int k)
    {
        if(!head) return NULL;
        int h=k;
        ListNode* tem=head;
        while(--h and head->next)
        {
            
            head=head->next;
        }
        
        if(h>0) return tem;
        
        
        ListNode* nextnode=head->next;
        head->next=NULL;
        
        ListNode* newhead=reverse(tem);
        ListNode* newnxtnode=fn(nextnode,k);
        
        ListNode* h1=newhead;
        while(h1->next)
        {
            h1=h1->next;
        }
        h1->next=newnxtnode;
        
        return newhead;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ansnode=fn(head,k);
        return ansnode;
    }
};