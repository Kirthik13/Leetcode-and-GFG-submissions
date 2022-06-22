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
    int getsize(ListNode* head)
    {
        int c=0;
        while(head)
        {
            c++;
            head=head->next;
        }
        return c;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next) return head;
        int n=getsize(head);
        k=k%n;
        if(k==0) return head;
        int reqnode=n-k+1;
        ListNode* h1=head;

        ListNode* prev;
        while(--reqnode and h1)
        {
            prev=h1;
            h1=h1->next;
        }
        prev->next=NULL;
        
        ListNode* h2=h1;
        while(h2->next)
        {
            h2=h2->next;
        }
        h2->next=head;
        return h1;
        
    }
};