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
    ListNode* mid(ListNode* head)
    {
        ListNode* f=head->next;
        ListNode* s=head;
        
        while(f and f->next)
        {
            s=s->next;
            f=f->next->next;
            
            
        }
        
        return s;
        
        
    }
    ListNode* rev(ListNode* head)
    {
        if(!head->next)
        {
            return head;
        }
        
        ListNode* ans=rev(head->next);
        head->next->next=head;
        head->next=NULL;
        return ans;
    }
        
        
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next) return 1;
        ListNode* nh1=head;
        ListNode* h2=head;
        ListNode* k1=mid(h2);
        ListNode* prev=k1->next;
        k1->next=NULL;
        k1=prev;
        ListNode *nh2=rev(k1);
        
        while(nh2 and nh1)
        {
            if(nh1->val!=nh2->val) return 0;
            nh1=nh1->next;
            nh2=nh2->next;
            
        }
        
        // if(nh1 or nh2) return 0;
        return 1;
            
    }
};