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
        ListNode *slow = head;
    ListNode *fast = head->next;
    
    while(slow->next != NULL && (fast!=NULL && fast->next!=NULL)) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
    }
    ListNode* sort(ListNode* l1,ListNode* l2)
    {
        ListNode* c1=l1;
        ListNode* c2=l2;
        ListNode* dum=new ListNode(-1);
        ListNode *curr=dum;
        
        while(c1 and c2)
        {
            if(c1->val<=c2->val)
            {
                curr->next=c1;
                c1=c1->next;
            }
            else
            {
                curr->next=c2;
                c2=c2->next;
            }
            
            curr=curr->next;
        }
        while(c1)
        {
            curr->next=c1;
            c1=c1->next;
            curr=curr->next;
       
        }
        while(c2)
        {
            curr->next=c2;
            c2=c2->next;
            curr=curr->next;
       
        }
        curr->next=NULL;
        return dum->next;
    }
    ListNode* merge(ListNode* l1)
    {
        if(!l1->next) return l1;
        ListNode* mid=midnode(l1);
        ListNode* l2=mid->next;
        mid->next=NULL;
        ListNode* newnode= sort(merge(l1),merge(l2));
        return newnode;
        
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 or !list2)
        {
            return !list1?list2:list1;
        }
        ListNode* l1=list1;
        ListNode* l2=list2;
        
        while(l1->next)
        {
            l1=l1->next;
        }
        l1->next=l2;
        
        return merge(list1);
    }
};