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
    ListNode* midnode(ListNode* head)
    {
        ListNode* s=head;
        ListNode* f=head->next;
        
        while(f and f->next)
        {
            f=f->next->next;
            s=s->next;
        }
        return s;
            
    }
    ListNode* reverse(ListNode* root)
    {
        if(!root->next) return root;
        
        ListNode* head=reverse(root->next);
        root->next->next=root;
        root->next=NULL;
        return head;
    }
    bool isPalindrome(ListNode* head) {
        if(!head->next) return 1;
        ListNode* mid=midnode(head);
        ListNode* newnode=mid->next;
        mid->next=NULL;
        ListNode* l1=head;
        ListNode* l2=reverse(newnode);
        while(l1 and l2)
        {
            if(l1->val!=l2->val) return 0;
            l1=l1->next;
            l2=l2->next;
      
        }
        // if(l1 or l2) return 0;
        return 1;
    }
};