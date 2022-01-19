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
        if(head==NULL)
        {
            return head;
        }
        
        ListNode* h=head;
                ListNode* f=head;
        ListNode* s=head;
    
    while(f and f->next)
    {
        f=f->next->next;

        // ListNode* t=s;
        s=s->next;
        if(f==s)
        {
           s=head;
            while(s!=f)
            {
                s=s->next;
                f=f->next;
            }
            
                            return f;

            // }
        }
    }
        // while(f and f->next)
        // {
        //     ListNode* k=f->next;
        //     if(m[k]==2)
        //     {
        //         return k;
        //     }
        //     f=f->next;
        // }
        
        return NULL;
       
        
    }
};