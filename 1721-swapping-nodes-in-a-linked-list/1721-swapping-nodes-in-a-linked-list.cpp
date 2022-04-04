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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head->next) return head;
        
//         ListNode* h1=head;
//         int k1=0,len{};
//                 ListNode* ans1=head;
//                 ListNode* ans2=head;

//         while(h1)
//         {
//             k1++;
//             if(k1==k)
//             {
//                 ans1=h1;
//             }
//             h1=h1->next;
            
//             len++;    
//         }
//         k=len-k+1;
//         k1=0;
//         h1=head;
//          while(h1)
//         {
//             k1++;
//             if(k1==k)
//             {
//                 ans2=h1;
//             }
//             h1=h1->next;
            
//             // len++;    
//         }
//         // cout<<ans1->val<<" "<<ans2->val<<endl;
//         swap(ans1->val,ans2->val);
//         return head;
        
        
        
        ListNode* ans1=head;
            ListNode* ans2=head;
        ListNode* h1=head;
        int f=0;
        while(h1)
        {
               // ans2 = ans2 == nullptr ? nullptr :ans2->next;
            if(--k==0)
            {
                ans1=h1;
                ans2=head;
                f=1;
            }
            
            h1=h1->next;
            if(!f){
            ans2=ans2->next;
            }
            f=0;
            
        }
        swap(ans1->val,ans2->val);
        return head;
        
    }
};