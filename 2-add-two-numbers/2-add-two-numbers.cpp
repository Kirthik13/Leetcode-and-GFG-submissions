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
    // ListNode* reverse(ListNode* root)
    // {
    //     if(!root->next)
    //     {
    //         return root;
    //     }
    //     ListNode* h=reverse(root->next);
    //     root->next->next=root;
    //     root->next=NULL;
    //     return h;
    // }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* l1=reverse(h1);
//         ListNode* l2=reverse(h2);
        
        ListNode* dum=new ListNode(-1);
        ListNode* curr=dum;
        int carry{};
        while(l1 and l2)
        {
            int sum=l1->val+l2->val+carry;
            
            curr->next=new ListNode(sum%10);
            carry=sum/10;
            curr=curr->next;
            
            l1=l1->next;
            l2=l2->next;

        }
        while(l1)
        {
            int sum=l1->val+carry;
            
            curr->next=new ListNode(sum%10);
            carry=sum/10;
            curr=curr->next;
            
            l1=l1->next;
        }
        while(l2)
        {
            int sum=l2->val+carry;
            
            curr->next=new ListNode(sum%10);
            carry=sum/10;
            curr=curr->next;
            
            
            l2=l2->next;
        }
        while(carry)
        {
            int sum=carry;
            curr->next=new ListNode(sum%10);
            carry=sum/10;
            curr=curr->next;
            
        }
        curr->next=NULL;
        // ListNode* ansnode=reverse(dum->next);
        // return ansnode;
        return dum->next;
        
    }
};