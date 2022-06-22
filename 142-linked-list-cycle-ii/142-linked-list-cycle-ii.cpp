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
    ListNode *detectCycle(ListNode *head) {
        ListNode* f=head;
        ListNode* s=head;
        int ch{};
        while(f and f->next)
        {
            f=f->next->next;
            s=s->next;
            if(f==s)
            {
                ch=1;
                break;    
            }
         
        }
        if(ch)
        {
                f=head;
                while(f and s)
                {
                       if(f==s)
                    {
                        return f;
                    }
                    f=f->next;
                    s=s->next;
                 
                }
        }
        return NULL;
    }
};