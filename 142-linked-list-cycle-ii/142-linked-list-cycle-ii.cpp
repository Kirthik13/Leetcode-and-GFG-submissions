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
        int cnt{};
        unordered_map<ListNode*,int>m;
        while(h)
        {
            if(m.find(h)==m.end()){
            m[h]++;
                
            }
            else{
                m[h]++;
                break;
            }
            h=h->next;
            ++cnt;
        }
//     while(f and f->next)
//     {
//         s=s->next;
//         f=f->next->next;
//         if(f==s)
//         {
//             if(cnt&1){
//             return f->next;
//             }
//             else{
//                             return f;

//             }
//         }
//     }
        while(f and f->next)
        {
            ListNode* k=f->next;
            if(m[k]==2)
            {
                return k;
            }
            f=f->next;
        }
        
        return NULL;
       
        
    }
};